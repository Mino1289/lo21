#ifndef __SLINKLIST_H__
#define __SLINKLIST_H__

#include <base.h>

#define EMPTY(l) (!l)
#define REST(l) (l->next)
#define HEAD(l) (l->data)

typedef struct _SL_elem {
    Data data;
    struct _SL_elem *next;
} SL_element;

typedef SL_element* SL_list;

void SL_print(SL_list l);

void SL_free(SL_list l);

int SL_size(SL_list l);

int SL_count(SL_list l, Data d);

bool SL_contains(SL_list l, Data d);

SL_list SL_insert_head(SL_list l, Data d);

SL_list SL_insert_tail(SL_list l, Data d);

SL_list SL_remove_head(SL_list l);

SL_list SL_remove_tail(SL_list l);

SL_list merge_sorted_lists(SL_list l1, SL_list l2);

void SL_sort_list(SL_list l);


#endif
