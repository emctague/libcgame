// libcgame: A simple, abstracted rendering library for C games, based on SDL.
// Copyright (C) 2019 Ethan McTague
// 
#include "cgmem.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// cg_initialized tracks if the cg_ context has been initialized and NOT UNINITIALIZED WITH cg_quit
int cg_initialized = 0;
// cg_initialized_once tracks if the cg_ context has been initialized EVER and is NOT undone by cg_quit
int cg_initialized_once = 0;

cg_mem_list cg_windows;


struct cg_window {
	CG_ITEMIZABLE
	SDL_Window *window;
	SDL_Renderer *renderer;
	cg_mem_list sprites;
	cg_mem_list instances;
};


struct cg_sprite {
	CG_ITEMIZABLE
	cg_window* window;
	SDL_Texture *texture;
	SDL_Rect rect;
};


void
cg_quit_atexit ()
{
	cg_quit ();
}


int
cg_init ()
{
	if (cg_initialized) return 0;

	if (!cg_initialized_once) atexit (cg_quit_atexit);

	if (SDL_Init (SDL_INIT_EVERYTHING) != 0)
		return 0;

	if (!(IMG_Init (CG_IMG_FORMATS) & CG_IMG_FORMATS))
		return 0;

	cg_new_mem_list(&cg_windows, sizeof(cg_window));

	cg_initialized = 1;
	cg_initialized_once = 1;

	return 1;
}


cg_window*
cg_new_window (const char* title, int width, int height)
{
	cg_window* window = (cg_window*) cg_mem_list_add (&cg_windows);

	cg_new_mem_list(&window->instances, sizeof (cg_instance));
	cg_new_mem_list(&window->sprites, sizeof (cg_sprite));

	#define WP SDL_WINDOWPOS_CENTERED
	window->window = SDL_CreateWindow (title, WP, WP, width, height, 0);

	if (window->window == NULL) {
		cg_mem_list_remove (&cg_windows, (cg_mem_item*) window);
		return NULL;
	}


	window->renderer = SDL_CreateRenderer (window->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (window->renderer == NULL) {
		SDL_DestroyWindow (window->window);
		cg_mem_list_remove (&cg_windows, (cg_mem_item*) window);
		return NULL;
	}

	return window;
}


cg_sprite*
cg_new_sprite (cg_window* window, const char* path)
{
	SDL_Surface *loaded = IMG_Load (path);

	if (loaded == NULL) return NULL;

	cg_sprite* spr = (cg_sprite*) cg_mem_list_add (&window->sprites);

	if (spr == NULL) return NULL;

	spr->texture = SDL_CreateTextureFromSurface (window->renderer, loaded);
	spr->window = window;

	if (spr->texture == NULL || SDL_QueryTexture (spr->texture, NULL, NULL, &spr->rect.w, &spr->rect.h) != 0) {
		if (spr->texture != NULL) SDL_DestroyTexture (spr->texture);
		cg_mem_list_remove (&window->sprites, (cg_mem_item*) spr);
		return NULL;
	}

	spr->rect.w *= CG_SCALE;
	spr->rect.h *= CG_SCALE;

	SDL_FreeSurface (loaded);

	return spr;
}


cg_instance*
cg_new_instance (cg_sprite* sprite)
{
	cg_instance* choice = (cg_instance*) cg_mem_list_add (&sprite->window->instances);

	if (choice == NULL) return NULL;

	choice->x = 0;
	choice->y = 0;
	choice->sprite = sprite;

	return choice;
}


int
cg_destroy_sprite (cg_sprite* sprite)
{
	SDL_DestroyTexture(sprite->texture);
	return cg_mem_list_remove (&sprite->window->sprites, (cg_mem_item*) sprite);
}


int
cg_destroy_instance (cg_instance* instance)
{
	return cg_mem_list_remove (&instance->sprite->window->instances, (cg_mem_item*) instance);
}


int 
cg_destroy_window (cg_window* window)
{
	while (window->instances.num > 0) {
		if (!cg_destroy_instance ((cg_instance*) window->instances.items[0]))
			return 0;
	}

	cg_destroy_mem_list (&window->instances);

	while (window->sprites.num > 0) {
		if (!cg_destroy_sprite ((cg_sprite*) window->sprites.items[0]))
			return 0;
	}

	cg_destroy_mem_list (&window->sprites);

	SDL_DestroyRenderer (window->renderer);
	SDL_DestroyWindow (window->window);

	return cg_mem_list_remove (&cg_windows, (cg_mem_item*) window);
}


int
cg_quit ()
{
	if (!cg_initialized) return 1;

	while (cg_windows.num > 0) {
		if (!cg_destroy_window ((cg_window*) cg_windows.items[0])) return 0;
	}

	cg_destroy_mem_list (&cg_windows);

	SDL_Quit ();

	cg_initialized = 0;

	return 1;
}


int
cg_update (cg_window* window)
{
	SDL_Event e;

	while (SDL_PollEvent (&e) != 0) {
		if (e.type == SDL_QUIT) return 0;
	}


	if (SDL_RenderClear (window->renderer) != 0) return 0;

	for (int i = 0; i < window->instances.num; i++) {
		cg_instance* instance = (cg_instance*) window->instances.items[i];

		instance->sprite->rect.x = instance->x * CG_SCALE;
		instance->sprite->rect.y = instance->y * CG_SCALE;

		if (SDL_RenderCopy (window->renderer, instance->sprite->texture,
			NULL, &instance->sprite->rect) != 0) return 0;
	}

	SDL_RenderPresent (window->renderer);

	return 1;
}


int
cg_get_key (cg_window* window, cg_key scancode)
{
	if (window == NULL || SDL_GetKeyboardFocus() == window->window) {
		const uint8_t* state = SDL_GetKeyboardState(NULL);
		return state[scancode];
	} else return 0;
}
