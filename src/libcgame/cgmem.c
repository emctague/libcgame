// libcgame Internal memory management system
#include "cgmem.h"
#include <malloc.h>


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

	if (list->capacity - list->num < 1) {
		list->capacity++;
		list->items = realloc (list->items, list->capacity * sizeof (cg_mem_item*));
	}

	mitem->cg_index = list->num;

	list->items[list->num++] = mitem;

	return mitem;
}


void
cg_mem_list_remove (cg_mem_list *list, cg_mem_item *item)
{
	list->num--;

	int index = item->cg_index;

	if (index < list->num) {
		list->items[index] = list->items[list->num];
		list->items[index]->cg_index = index;
	}

	if (list->capacity - list->num > CG_MEM_EXTRAS) {
		list->capacity = list->num;
		list->items = realloc (list->items, list->capacity * sizeof (cg_mem_item*));
	}

	free (item);
}


void
cg_destroy_mem_list (cg_mem_list* list)
{
	free (list->items);
}