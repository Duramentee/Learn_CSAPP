#include <stdio.h>
#include <stdlib.h>

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	for (size_t i  = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show(int val)
{
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;

	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main(int argc, char const *argv[]) {
	int val = 0x87654321;
	byte_pointer valp = (byte_pointer) &val;

	show_bytes(valp, 1);
	printf("\n");
	show_bytes(valp, 2);
	printf("\n");
	show_bytes(valp, 3);
	printf("\n");
	
	return 0;
}