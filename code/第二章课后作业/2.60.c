/*
 * replace-byte.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

unsigned int replace_byte(unsigned int x, int i, unsigned char b) {
    // i 不可为负数
    if (i < 0) {
        puts("error: i is negative.");
        return x;
    }
    // i 超过了 unsigned int 可替换的最大位(可替换位为0,1,2,3)
    if (i >= sizeof(unsigned int)) {
        puts("error: i is too big.");
        return x;
    }

    // i<<3 也就是 i*8 目的是将二进制表示的bit位转为Byte(8bit).
    // 掩码为 1Byte(8bit) 的全1数, 通过 <<(i<<3) 将掩码位移到要替换的位置处.
    unsigned int mask = ((unsigned int) 0xFF) << (i << 3);
    // 类似上一步,将 b 移动到要替换的位置处.
    unsigned int pos_byte = ((unsigned int) b) << (i << 3);

    // x & ~mask 目的除去目标位置处的值
    // 之后再 | pos_byte 合并上要替代的值
    return (x & ~mask) | pos_byte;
}

int main(void) {
    unsigned rep_0 = replace_byte(0x12345678, 0, 0xAB);
    unsigned rep_3 = replace_byte(0x12345678, 3, 0xAB);

    assert(rep_0 == 0x123456AB);
    assert(rep_3 == 0xAB345678);
    return 0;
}
