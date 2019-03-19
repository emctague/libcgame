// libcgame Internal memory management system
#include "cgmem.h"
#include <malloc.h>

// Internal resize function
int
cg_mem_list_resize (cg_mem_list* list, int newcap)
{
	void* items = realloc (list->items, newcap * sizeof (cg_mem_item*));

	if (items == NULL) return 0;
	
	list->capacity = newcap;
	list->items = items;

	return 1;
}

void
cg_new_mem_list (cg_mem_list* list, int itemsize)
{
	list->items = 0;
	list->num = 0;
	list->capacity = 0;
	list->itemsize = itemsize;
}


cg_mem_item*
cg_mem_list_add (cg_mem_list* list)
{
	cg_mem_item* mitem = malloc (list->itemsize);

	if (mitem == NULL) return NULL;

	if (list->capacity - list->num < 1) {
		if (!cg_mem_list_resize (list, list->capacity + 1)) {
			free (mitem);
			return NULL;
		}
	}

	mitem->cg_index = list->num;

	list->items[list->num++] = mitem;

	return mitem;
}


int
cg_mem_list_remove (cg_mem_list *list, cg_mem_item *item)
{
	list->num--;

	int index = item->cg_index;

	if (index < list->num) {
		list->items[index] = list->items[list->num];
		list->items[index]->cg_index = index;
	}

	if (list->capacity - list->num > CG_MEM_EXTRAS) {
		if (!cg_mem_list_resize (list, list->num)) {
			return 0;
		}
	}

	free (item);
	return 1;
}


void
cg_destroy_mem_list (cg_mem_list* list)
{
	free (list->items);
}