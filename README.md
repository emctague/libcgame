# libcgame

`libcgame` is a simplified window + rendering library for C.

It wraps the commonly-used `SDL2` library, providing features such as automatic destruction
of objects, and keeping track of items to render internally.

This library IS NOT intended for complex, professional game engines and games. It is intended
only to simplify the process of creating smaller projects.

For an example, see `test/test.c`.

## Building and Installing

 - Install SDL2 and SDL2_image in such a way that it can be found with pkg-config

 - Make a `build` directory under the project directory and enter it

 - Invoke `cmake ..`

 - Invoke `make`

 - Invoke `make install`

You will now be able to link with cgame globally (`-lcgame`) and use it (`#include <libcgame.h>`) in your C projects.

## A Warning

If you're not a lazy ass like me you're FAR better off using SDL2 directly. I mainly just made this to
simplify my own smaller 2D projects.
