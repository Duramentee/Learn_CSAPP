 
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

bool int_shifts_are_arithmetic() {
	// num 为 1111 1111 1111 1111 1111 1111 1111 1111
	const int num = -1;
	// 如果为算数右移则 num>>1,将得到
	// 1111 1111 1111 1111 1111 1111 1111 1111
	// 如果为逻辑右移则将得到
	// 0111 1111 1111 1111 1111 1111 1111 1111
	// ^ 异或操作比较 num 和 num>>1 的差异,两者不同(逻辑右移)返回真,相同(算术右移)返回假
	// 最后取反,则为真代表算数右移,为假代表逻辑右移
	return !(num ^ (num >> 1));
}

int main(void)
{
	assert(int_shifts_are_arithmetic());
	return 0;
}