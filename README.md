# libcgame

`libcgame` is a simplified window + rendering library for C.

It wraps the commonly-used `SDL2` library, providing features such as automatic destruction
of objects, and keeping track of items to render internally.

This library IS NOT intended for complex, professional game engines and games. It is intended
only to simplify the process of creating smaller projects.

For an example, see `src/test/test.c`.
