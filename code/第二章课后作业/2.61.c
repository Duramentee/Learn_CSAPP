/*
 * 2.61.c
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// 以下函数在面熟的条件下产生 1, 而在其他情况下得到 0 ,假定 x 类型为 int
// x 的任何位都等于 1
bool all_one(const int x) {
    return !~x;
}

// x 的任何位都等于 0
bool all_zero(const int x) {
    return !x;
}

// x 的最低有效字节中的位都等于 1
bool least_all_one(const int x) {
    // x | ~0xFF 获取最低有效字节
    // 对于数 00000000 00000000 00000000 11111111, 最低字节就是 11111111, 最高字节就是 00000000
    // 注意!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // 虽然说 0xFF 本身在c语言中是 unsigned int 类型,但是在此处配合下能够完成提取最低有效字节
    // 0xFF  是 00000000 00000000 00000000 11111111
    // ~0xFF 是 11111111 11111111 11111111 00000000
    // 再配合函数 all_one, all_one 将会 判断所有位都为1, 但是经过和掩码做 | 操作之后,不论x原先的最高24位是不是1,最后都会变为1
    // 也就是说无需关注最高的24位,在实际上产生的作用就是获取到了"有效字节"
    return all_one(x | ~0xFF);
}

// x 的最高有效字节中的位都等于 0
bool most_all_zero(const int x) {
    // (x >> ((sizeof(int)-1) << 3)) & 0xff 获取最高有效字节
    // 和上面的 least_all_one 函数分析过程类似,通过相同的手段,尽管 0xFF 是一个 32 位数,但是操作后也可达到仅获取有效字节的效果
    return all_zero((x >> ((sizeof(int)-1) << 3)) & 0xFF);
}

int main(void) {
    int all_bit_one = ~0;
    int all_bit_zero = 0;

    assert(all_one(all_bit_one));
    assert(!all_zero(all_bit_one));
    assert(least_all_one(all_bit_one));
    assert(!most_all_zero(all_bit_one));

    assert(!all_one(all_bit_zero));
    assert(all_zero(all_bit_zero));
    assert(!least_all_one(all_bit_zero));
    assert(most_all_zero(all_bit_zero));

    // test magic number 0x1234ff
    assert(!all_one(0x1234ff));
    assert(!all_zero(0x1234ff));
    assert(least_all_one(0x1234ff));
    assert(most_all_zero(0x1234ff));

    // test magic number 0x1234
    assert(!all_one(0x1234));
    assert(!all_zero(0x1234));
    assert(!least_all_one(0x1234));
    assert(most_all_zero(0x1234));

    return 0;
}
