#include <tree.h>

void T_print_prefix(Tree *t) {
    if (!EMPTY(t)) {
        D_print(ROOT(t));
        T_print_prefix(LEFT(t));
        T_print_prefix(RIGHT(t));
    }
} 

void T_print_postfix(Tree *t) {
    if (!EMPTY(t)) {
        T_print_postfix(LEFT(t));
        T_print_postfix(RIGHT(t));
        D_print(ROOT(t));
    }
} 

void T_print_infix_lr(Tree *t) {
    if (!EMPTY(t)) {
        T_print_infix_lr(LEFT(t));
        D_print(ROOT(t));
        T_print_infix_lr(RIGHT(t));
    }
} 

void T_print_infix_rl(Tree *t) {
    if (!EMPTY(t)) {
        T_print_infix_rl(RIGHT(t));
        D_print(ROOT(t));
        T_print_infix_rl(LEFT(t));
    }
}

void T_free(Tree *t) {
    if (!EMPTY(t)) {
        T_free(LEFT(t));
        T_free(RIGHT(t));
        D_free(&ROOT(t));
        free(t);
    }
}

int T_size(Tree *t) {
    if (EMPTY(t)) {
        return 0;
    } else {
        return 1 + T_size(LEFT(t)) + T_size(RIGHT(t));
    }
}

int T_count(Tree *t, Data d) {
    if (EMPTY(t)) {
        return 0;
    } else {
        return (D_cmp(ROOT(t), d) == 0 ? 1 : 0) + T_count(LEFT(t), d) + T_count(RIGHT(t), d);
    }
}

int T_node_count(Tree *t) {
    if (EMPTY(t)) {
        return 0;
    } else {
        return 1 + T_node_count(LEFT(t)) + T_node_count(RIGHT(t));
    }
}

int T_leaf_count(Tree *t) {
    if (EMPTY(t)) {
        return 0;
    } else if (LEAF(t)) {
        return 1;
    } else {
        return T_leaf_count(LEFT(t)) + T_leaf_count(RIGHT(t));
    }
}

bool T_contains(Tree *l, Data d) {
    if (EMPTY(l)) {
        return false;
    } else {
        return (D_cmp(ROOT(l), d) == 0) || T_contains(LEFT(l), d) || T_contains(RIGHT(l), d);
    }
}

Tree *new(Data d) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    ROOT(t) = d;
    LEFT(t) = NULL;
    RIGHT(t) = NULL;
    return t;
}

Tree *root(Tree *right, Tree *left, Data d) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    ROOT(t) = d;
    LEFT(t) = left;
    RIGHT(t) = right;
    return t;
}
