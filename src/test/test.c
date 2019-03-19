#include "../libcgame/libcgame.h"
#include <assert.h>

int
main (int argc, char** argv)
{
	assert(cg_init () == 0);

	cg_window* window = cg_new_window ("libcgame test", 1024, 768);

	cg_sprite* sprite = cg_new_sprite (window, "src/test/sprite.png");

	cg_instance* instance = cg_new_instance (sprite);

	cg_instance* i2 = cg_new_instance (sprite);

	cg_instance* i3 = cg_new_instance (sprite);

	while (cg_update (window)) {
		if (cg_get_key(window, CG_KEY_RIGHT))
			instance->x++;
	}

	cg_quit ();

	return 0;
}
