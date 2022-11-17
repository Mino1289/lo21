#include <base.h>

void D_print(Data d) {
    printf("%d\n", d.value);
}

int D_cmp(Data d1, Data d2) {
    if (VALUE(d1) > VALUE(d2)) {
        return 1;
    } else if (VALUE(d1) < VALUE(d2)) {
        return -1;
    } else {
        return 0;
    }
}
