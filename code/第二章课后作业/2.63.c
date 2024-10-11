/*
 * srl-sra.c
 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// 第一个函数用 算数右移 实现 逻辑右移
unsigned int srl(unsigned int x, int k)
{
	// 题目要求如此,x 强转为 int 变为有符号类型,之后算术右移 k 位.
	const unsigned int xsra = (int) x >> k;

	// w 也就是 4 * 2^3 = 32
	const int w = sizeof(int) << 3;
	// 建立一个掩码,题目不允许用右移,那么就用左移加取反作为代替
	// 右移k,也就是左移(w-k)然后取反.
	const int mask = (int) -1 << (w - k);

	// 最后再用 xsra 与 取反的mask(目的是将本来经过算数右移得到的最高位全为1的值变为0)相与.
	return xsra & ~mask;
}

int sra(int x, int k)
{
	int xsrl = (unsigned int) x >> k;

	const int w = sizeof(int) << 3;
	int mask = (int) -1 << (w - k);
	// 这里创建一个值为 2^(w-1) 的常量 m，即只在最高位上有 1，其余位为 0，用于检测 x 的符号位
	const int m = 1 << (w - 1);
	// 这一行目的是调整掩码 mask。 x & m 用于检查 x 的符号位，
	// 如果符号位是 1（表示 x 是负数），则 !(x & m) 为 0，因此 mask 不会被改变为 0；
	// 如果符号位是 0（表示 x 是非负数），则 !(x & m) 为 1，减去 1 后会让 mask 变为 0。
	// 这样，最终的 mask 变量会使得对于负数 (x 的符号为 1)，mask 保持不变；而对于非负数，则将其设为 0。
	mask &= ! (x & m) - 1;
	// 最终返回的结果是 xsrl 和 mask 的按位或操作。
	// 这个操作的意义在于：对于负数，mask 将保留整个原始算术右移得到的结果，
	// 而对于非负数，则会返回 xsrl 的结果，即不影响其值。
	return xsrl | mask;
}

int main(void)
{
	unsigned test_unsigned = 0x12345678;
	int test_int = 0x12345678;

	assert(srl(test_unsigned, 4) == test_unsigned >> 4);
	assert(sra(test_int, 4) == test_int >> 4);

	test_unsigned = 0x87654321;
	test_int = 0x87654321;

	assert (srl (test_unsigned, 4) == test_unsigned >> 4);
	assert (sra (test_int, 4) == test_int >> 4);
	return 0;
}
