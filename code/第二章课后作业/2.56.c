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

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)val;
    int* pval = &val;

    show_int(val);
    show_float(fval);
    show_pointer(pval);
}

int main(void) {
    int test_num1 = 328;
    int test_num2 = 329;
    int test_num3 = 330;

    test_show_bytes(test_num1);
    puts("");
    test_show_bytes(test_num2);
    puts("");
    test_show_bytes(test_num3);

    return 0;
}
