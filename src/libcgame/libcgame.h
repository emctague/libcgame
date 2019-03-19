// libcgame: A simple, abstracted rendering library for C games, based on SDL.
// Copyright (C) 2019 Ethan McTague
// 
#pragma once
#include "cgmem.h"
#include "cgkeys.h"

// CG_IMG_FORMATS is the image format data supplied to SDL's IMG_Init.
#ifndef CG_IMG_FORMATS
#define CG_IMG_FORMATS (IMG_INIT_PNG)
#endif

// CG_SCALE is used to scale up all sprites onscreen for a pixel-art effect.
#ifndef CG_SCALE
#define CG_SCALE 3
#endif

// A cg_window represents a window onscreen.
typedef struct cg_window cg_window;

// A cg_sprite represents a sprite image that can be drawn onscreen.
typedef struct cg_sprite cg_sprite;

// A cg_instance is a handle for an item being drawn onscreen. 
typedef struct cg_instance {
	CG_ITEMIZABLE
	int x, y;
	cg_sprite* sprite;

	int index; // Internal index tracker, DO NOT TOUCH
} cg_instance;

// Must be called before any cg_ operations - initializes the library.
int
cg_init ();

// Should be called at the end of the program to clean up. This will automatically
// destroy all items initialized using cg_new_<> functions that have not yet been destroyed
// properly.
void
cg_quit ();

// Creates a new window.
cg_window*
cg_new_window (const char* title, int width, int height);

// Creates a new sprite.
cg_sprite*
cg_new_sprite (cg_window* window, const char* path);

// Creates a new instance that will be drawn onscreen.
cg_instance*
cg_new_instance (cg_sprite* sprite);

// Destroys the given sprite.
void
cg_destroy_sprite (cg_sprite* sprite);

// Destroys an instance, causing it to no longer be drawn onscreen.
void
cg_destroy_instance (cg_instance* instance);

// Destroys a window and all its associated objects (sprites, instances, etc.)
void
cg_destroy_window (cg_window* window);

// Processes any events and then renders the frame, returning '1' unless the
// window has been requested to close.
int
cg_update (cg_window* window);

// Check if the given key is pressed.
// Pass NULL for window to get the global (non-focus-dependent) key state.
// Note that non-focus-dependent key state is unreliable.
int
cg_get_key (cg_window* window, cg_key scancode);
