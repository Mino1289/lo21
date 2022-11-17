#include <slinklist.h>

void SL_print(SL_list l) {
    if (!EMPTY(l)) {
        D_print(HEAD(l));
        SL_print(l->next);
    }
}

void SL_free(SL_list l) {
    D_free(&HEAD(l));
    free(l);
}

int SL_size(SL_list l) {
    if (EMPTY(l)) {
        return 0;
    }
    return 1 + SL_size(l->next);
}

int SL_count(SL_list l, Data d) {
    if (EMPTY(l)) {
        return 0;
    }
    if (D_cmp(HEAD(l), d) == 0) {
        return 1 + SL_count(l->next, d);
    } else {
        return SL_count(l->next, d);
    }
}

bool SL_contains(SL_list l, Data d) {
    if (EMPTY(l)) {
        return false;
    }
    if (D_cmp(HEAD(l), d) == 0) {
        return true;
    }
    return SL_contains(l->next, d);
}

SL_list SL_insert_head(SL_list l, Data d) {
    SL_list new = (SL_list) malloc(sizeof(SL_element));
    new->data = d;
    new->next = l;
    return new;
}

SL_list SL_insert_tail(SL_list l, Data d) {
    SL_list new = (SL_list) malloc(sizeof(SL_element));
    new->data = d;
    new->next = NULL;
    if (EMPTY(l)) {
        return new;
    } else {
        SL_list tmp = l;
        while (!EMPTY(REST(tmp))) {
            tmp = REST(tmp);
        }
        REST(tmp) = new;
        return l;
    }
}

SL_list SL_remove_head(SL_list l) {
    if (EMPTY(l)) {
        return NULL;
    } else {
        SL_list tmp = REST(l);
        SL_free(l);
        return tmp;
    }
}

SL_list SL_remove_tail(SL_list l) {
    if (EMPTY(l)) {
        return NULL;
    } else if (EMPTY(REST(l))) {
        SL_free(l);
        return NULL;
    } else {
        SL_list tmp = l;
        while (!EMPTY(REST(REST(l)))) {
            tmp = REST(tmp);
        }
        SL_free(REST(tmp));
        REST(tmp) = NULL;
        return l;
    }
}

SL_list merge_sorted_lists(SL_list l1, SL_list l2) {
    SL_list tmp1 = l1;
    SL_list tmp2 = l2;
    SL_list new = NULL;
    while (!EMPTY(tmp1) && !EMPTY(tmp2)) {
        if (D_cmp(HEAD(tmp1), HEAD(tmp2)) < 0) {
            new = SL_insert_tail(new, HEAD(tmp1));
            tmp1 = REST(tmp1);
        } else {
            new = SL_insert_tail(new, HEAD(tmp2));
            tmp2 = REST(tmp2);
        }
    }
    while (!EMPTY(tmp1)) {
        new = SL_insert_tail(new, HEAD(tmp1));
        tmp1 = REST(tmp1);
    }
    while (!EMPTY(tmp2)) {
        new = SL_insert_tail(new, HEAD(tmp2));
        tmp2 = REST(tmp2);
    }
    return new;
}

void SL_sort_list(SL_list l) {
    bool inv = false;
    SL_list p = l;
    SL_list f = NULL;
    if (!EMPTY(p) && !EMPTY(REST(p))) {
        do {
            inv = false;
            p = l;
            while (REST(p) != f) {
                if (D_cmp(HEAD(p), HEAD(REST(p))) > 0) {
                    SWAP(HEAD(p), HEAD(REST(p)), Data);
                    inv = true;
                }
                p = REST(p);
            }
            f = p;
        } while (inv);
    }
}

