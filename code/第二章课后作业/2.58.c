/*
 * is-little-endian.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// unsigned char 是一个 8bit 无符号数(也就是1Byte),
// 用这个数可以表示 int(4Byte), long(8Byte) 之类的其他数
typedef unsigned char* byte_pointer;

bool is_little_endian() {
    int test_num = 0xff; // 也就是二进制的 1111 1111(此处省略了前面的 32-8=24 个0)
    byte_pointer byte_start = (byte_pointer) &test_num;

    // byte_start[0] 认为是 *(byte_start + 0) 的语法糖,将获取最低地址(假定为0x00)的值.
    // 如果有 byte_start[1] 的话,将访问次低地址(0x00后一个,也就是0x01).
    // 因此如果为小端存储,那么最低地址就将存储 1111 1111
    // 如果为大端存储,那么最低地址就将存储 0000 0000
    return byte_start[0] == 0xff;
}

// 在x86处理器上能够断言成功(也就是x86小端机器)
int main(void) {
    assert(is_little_endian());
    return 0;
}