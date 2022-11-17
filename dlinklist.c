#include <dlinklist.h>

void DL_print(DL_list l) {
    if (!EMPTY(l)) {
        D_print(HEAD(l));
        DL_print(l->next);
    }
}

void DL_print_reverse(DL_list l) {
    if (!EMPTY(l)) {
        DL_print_reverse(l->next);
        D_print(HEAD(l));
    }
}

void DL_free(DL_list l) {
    D_free(&HEAD(l));
    free(l);
}

int DL_size(DL_list l) {
    if (EMPTY(l)) {
        return 0;
    }
    return 1 + DL_size(l->next);
}

int DL_count(DL_list l, Data d) {
    if (EMPTY(l)) {
        return 0;
    }
    if (D_cmp(HEAD(l), d) == 0) {
        return 1 + DL_count(l->next, d);
    } else {
        return DL_count(l->next, d);
    }
}

bool DL_contains(DL_list l, Data d) {
    if (EMPTY(l)) {
        return false;
    }
    if (D_cmp(HEAD(l), d) == 0) {
        return true;
    }
    return DL_contains(l->next, d);
}

DL_list DL_insert_head(DL_list l, Data d) {
    DL_list new = (DL_list) malloc(sizeof(DL_element));
    HEAD(new) = d;
    REST(new) = l;
    BEFORE(new) = NULL;
    if (!EMPTY(l)) {
        BEFORE(l) = new;
    }
    return new;
}

DL_list DL_insert_tail(DL_list l, Data d) {
    if (!EMPTY(l)) {
        DL_list tmp = l;
        while (!EMPTY(REST(tmp))) {
            tmp = REST(tmp);
        }
        DL_list new = (DL_list) malloc(sizeof(DL_element));
        HEAD(new) = d;
        REST(new) = NULL;
        BEFORE(new) = tmp;
        REST(tmp) = new;
        return l;
    } else {
        return DL_insert_head(l, d);
    }
}

DL_list DL_remove_head(DL_list l) {
    if (EMPTY(l)) {
        return l;
    } else if (EMPTY(REST(l))) {
        DL_free(l);
        return NULL;
    } else {
        DL_list tmp = REST(l);
        BEFORE(tmp) = NULL;
        DL_free(l);
        return tmp;
    }
}

DL_list DL_remove_tail(DL_list l) {
    if (EMPTY(l)) {
        return l;
    } else if (EMPTY(REST(l))) {
        DL_free(l);
        return NULL;
    } else {
        DL_list tmp = l;
        while (!EMPTY(REST(tmp))) {
            tmp = REST(tmp);
        }
        REST(BEFORE(tmp)) = NULL;
        DL_free(tmp);
        return l;
    }
}

DL_list insert_sorted(DL_list l, Data d) {
    if (EMPTY(l) || D_cmp(d, HEAD(l)) < 0) {
        return DL_insert_head(l, d);
    }
    DL_list tmp = l;
    while (!EMPTY(tmp)) {
        if (D_cmp(d, HEAD(tmp)) >= 0) {
            DL_list new = (DL_list) malloc(sizeof(DL_element));
            REST(new) = REST(tmp);
            if (!EMPTY(REST(new))) {
                BEFORE(REST(new)) = new;
            }
            REST(tmp) = new;
            BEFORE(new) = tmp;
            HEAD(new) = d;
            tmp = NULL;
        } else {
            tmp = REST(tmp);
        }
    }
    return l;
}

