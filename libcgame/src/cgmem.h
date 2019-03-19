// libcgame Internal memory management system
#pragma once
#define CG_INTERNAL
#include <libcgame.h>

#define CG_ITEMIZABLE int cg_index;


// CG_MEM_EXTRAS is the number of acceptable unused slots in a list
// before extras are freed.
#ifndef CG_MEM_EXTRAS
#define CG_MEM_EXTRAS 10
#endif


// A cg_mem_item is an item that keeps track of its index in a cg_mem_list.
// This is a template for any CG_ITEMIZABLE.
typedef struct cg_mem_item {
	CG_ITEMIZABLE
} cg_mem_item;


// A cg_mem_list is a generic vector type.
typedef struct cg_mem_list {
	cg_mem_item** items;
	int num, capacity, itemsize;
} cg_mem_list;


// Initializes the given cg_mem_list. itemsize should be the sizeof() result for the structure being stored.
// The structure being stored must have the "CG_ITEMIZABLE" macro inside its definition BEFORE any other members.
void
cg_new_mem_list (cg_mem_list* list, int itemsize);


// Adds the given item pointer to a cg_mem_list and returns its assigned index
cg_mem_item*
cg_mem_list_add (cg_mem_list* list);


// Removes the given item index from the cg_mem_list AND FREES IT.
void
cg_mem_list_remove (cg_mem_list* list, cg_mem_item* item);


// Destroy a cg_mem_list - ALL CHILDREN MUST BE DESTROYED SAFELY FIRST, AND THE LIST OBJECT ITSELF SHOULD BE FREED
// AFTERWARD
void
cg_destroy_mem_list (cg_mem_list* list);
