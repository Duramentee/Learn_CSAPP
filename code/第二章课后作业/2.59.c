/*
 * generate-a-word.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

size_t generate_a_word(const size_t x, const size_t y) {
    // 目的是保留x在16进制下的的最后两位,那么用0xff
    const size_t mask = 0xff;
    // x & mask 保留最后两位, y & ~mask 保留除了最后两位的
    // | 运算符将两者合并(毕竟除了0就是1)
    return ((x & mask) | (y & ~mask));
}

int main(void) {
    const size_t x = 0x89ABCDEF;
    const size_t y = 0x76543210;
    const size_t res = generate_a_word(x, y);
    // 保留x后两位和y除了后两位,得到的结果就将如下
    assert(res == 0x765432EF);

    return 0;
}
