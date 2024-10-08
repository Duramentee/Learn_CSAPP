#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y) {
	*y = *x ^ *y; /* Step 1 */
	*x = *x ^ *y; /* Step 2 */
	*y = *x ^ *y; /* Step 3 */
}
// 例如 *x = a, *y = b
// Step 1  y = a ^ b
// Step 2  x = a ^ b ^ a = a ^ a ^ b = 0 ^ b = b
// Step 3  y = b ^ a ^ b = b ^ b ^ a = 0 ^ a = a
// 完成了交换

/*
void reverse_array(int a[], int cnt) {
	int first = 0;
	int last = cnt - 1;
	for (; first <= last; ++first, --last) {
		inplace_swap(&a[first], &a[last]);
	}
}
*/

void reverse_array(int a[], int cnt) {
	int first = 0;
	int last = cnt - 1;
	for (; first != last; ++first, --last) {
		inplace_swap(&a[first], &a[last]);
	}
}

void print_arr(int a[], int cnt) {
	for (int i = 0; i < cnt; ++i) {
		printf("%i ", a[i]);
	}
}

int main() {
	int a = 1;
	int b = 2;
	// 将输出 1 2
	printf("%i %i\n", a, b);

	inplace_swap(&a, &b);
	// 将输出 2 1
	printf("%i %i\n", a, b);

	int arr[5] = { 1, 2, 3, 4, 5 };

	// 将输出 1 2 3 4 5
	print_arr(arr, 5);
	printf("\n");

	// 将输出 5 4 0 2 1
	// 原因在于 first <= last, 改成 first != last 即可输出 5 4 3 2 1
	reverse_array(arr, 5);
	print_arr(arr, 5);
	printf("\n");

	return 0;
}