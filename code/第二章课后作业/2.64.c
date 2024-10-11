 
/*
 * any-odd-one.c
 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool any_odd_one(const unsigned x) {
	// 0xAAAAAAAA 也就是 10101010101010101010101010101010,偶数位全为0,奇数位全为1
	return !!(0xAAAAAAAA & x);
}

int main(void)
{
	assert(any_odd_one(0x2));
	assert(!any_odd_one(0x4));
	return 0;
}
