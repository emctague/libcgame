#include <libcgame.h>
#include <assert.h>

extern void cg_data_test();

int
main (int argc, char** argv)
{
	assert(cg_init ());

	cg_window* window = cg_new_window ("libcgame test", 1024, 768);

	cg_sprite* sprite = cg_new_sprite (window, "test/sprite.png");

	cg_instance* instance = cg_new_instance (sprite);
	assert (instance);

	cg_instance* i2 = cg_new_instance (sprite);
	assert (i2);

	cg_instance* i3 = cg_new_instance (sprite);
	assert (i3);

	cg_instance* i4 = cg_new_instance (sprite);
	assert (i4);

	while (cg_update (window)) {
		if (cg_get_key(window, CG_KEY_RIGHT)) {
			instance->x++;
			i2->x++;
			i2->y++;
			i3->y++;
		}

		if (cg_get_key(window, CG_KEY_SPACE) && i4 != 0) {
			cg_destroy_instance(i3);
			i3 = i4;
			i4 = 0;
		}
	}

	assert(cg_quit ());

	return 0;
}
