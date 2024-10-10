/*
 * show-bytes.c
 */

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(short val) {
    short sval = val;
    long lval = (long)val;
    double dval = (double) val;
    short* pval = &val;

    show_short(sval);
    show_long(lval);
    show_double(dval);
    show_pointer(pval);
}

int main(void) {
    short test_num1 = 328;
    short test_num2 = 329;
    short test_num3 = 330;

    test_show_bytes(test_num1);
    puts("");
    test_show_bytes(test_num2);
    puts("");
    test_show_bytes(test_num3);

    return 0;
}
