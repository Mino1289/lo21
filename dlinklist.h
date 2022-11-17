#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__

#include <base.h>
#include <slinklist.h>

#define BEFORE(l) (l->prev)

typedef struct _DL_elem {
    Data data;
    struct _DL_elem *next;
    struct _DL_elem *prev;
} DL_element;

typedef DL_element* DL_list;

void DL_print(DL_list l);

void DL_print_reverse(DL_list l);

void DL_free(DL_list l);

int DL_size(DL_list l);

int DL_count(DL_list l, Data d);

bool DL_contains(DL_list l, Data d);

DL_list DL_insert_head(DL_list l, Data d);

DL_list DL_insert_tail(DL_list l, Data d);

DL_list DL_remove_head(DL_list l);

DL_list DL_remove_tail(DL_list l);

DL_list insert_sorted(DL_list l, Data d);

#endif
