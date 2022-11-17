#ifndef __TREE_H__
#define __TREE_H__

#include <base.h>

#define ROOT(t) (t->data)
#define LEFT(t) (t->left)
#define RIGHT(t) (t->right)

#define LEAF(t) (EMPTY(LEFT(t)) && EMPTY(RIGHT(t)))

typedef struct _T_elem {
    Data data;
    struct _T_elem *left;
    struct _T_elem *right;
} Tree;


void T_print_prefix(Tree *t);

void T_print_postfix(Tree *t);

void T_print_infix_lr(Tree *t);

void T_print_infix_rl(Tree *t);

void T_free(Tree *t);

int T_size(Tree *t);

int T_count(Tree *t, Data d);

int T_node_count(Tree *t);

int T_leaf_count(Tree *t);

bool T_contains(Tree *l, Data d);

Tree *new(Data d);

Tree *root(Tree *right, Tree *left, Data d);


#endif // __TREE_H__
