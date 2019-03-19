# libcgame

`libcgame` is a simplified window + rendering library for C.

It wraps the commonly-used `SDL2` library, providing features such as automatic destruction
of objects, and keeping track of items to render internally.

This library IS NOT intended for complex, professional game engines and games. It is intended
only to simplify the process of creating smaller projects.


## Example

```c
#include <libcgame.h>

int
main (int argc, char** argv)
{
	cg_init ();

	cg_window* window = cg_new_window ("Hello, World", 1024, 768);

	// A drawable image
	cg_sprite* sprite = cg_new_sprite (window, "pixel_art.png");

	// An actual visible instance of a sprite you can see onscreen
	cg_instance* instance = cg_new_instance (sprite);

	// Main game loop
	while (cg_update (window)) {

		// Keyboard movement
		if (cg_get_key(window, CG_KEY_RIGHT)) instance->x++;
		if (cg_get_key(window, CG_KEY_LEFT)) instance->x--;
	}

	return 0;
}
```


## Building and Installing

 - Install SDL2 and SDL2_image in such a way that it can be found with pkg-config

 - Make a `build` directory under the project directory and enter it

 - Invoke `cmake ..`

 - Invoke `make`

 - Invoke `make install`

You will now be able to link with cgame globally (`-lcgame`) and use it (`#include <libcgame.h>`) in your C projects.

## A Warning

For most projects, you're FAR better off using SDL2 directly.
This library is only particularly useful for small experiments - it can only render 2D sprites, and does so with
linear upscaling (for a pixel-art-esque style.)

## Project Patterns


### Objects

`cgame` uses class-like structs (`cg_<name>`).

For every class-like struct, there exists a function `cg_new_<name>`, which accepts properties for the new object as
arguments, and returns a pointer to the created object (or `NULL` on failure.)

Structs will often be considered dependent on some other object (i.e. every `cg_sprite` is created for a specific `cg_window`),
in which case the parent object will keep track of this relationship and ensure the children are safely destroyed when it is.

For each such struct there also exists a function `cg_destroy_<name>`, which accepts a pointer to a created object and
deinitializes it safely, including destroying any children it may have.

### Dynamic Arrays

Internally, parent-child relationships are tracked using a dynamic array implementation, `cg_mem_list`.
These arrays are intended to handle additions and removals at any index rapidly, including quickly removing items not located
at the ends of the array.

Because of this, array items need to be reordered without notifying any other components which use these array items. Thus,
any data-type being used in such an array must contain an `int` as its first member, used to track the index. This should be
done by inserting `CG_ITEMIZABLE` immediately after the opening brace of the struct. This member will be updated automatically.

A consequence of this implementation is that objects used in a `cg_mem_list` may ONLY be members of ONE `cg_mem_list` at a time.
To enforce this, `cg_mem_list` instances are made aware of the allocation size of the type they contain, and are responsible for
allocation and deallocation of member objects. Because most object types in `cgame` are inherently members of some parent-child
relationship listing, this means that `cg_new_<name>` and `cg_destroy_<name>` methods heavily rely on `cg_mem_list` for allocating
and freeing memory.
