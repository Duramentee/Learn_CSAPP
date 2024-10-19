/*
 * decode.c
 */

// 不解释了,直接对着换就行,这里可以定义一个新变量tmp,也可以继续用y,都一样.

long decode(long x, long y, long z) {
  long tmp = y - z;
  return (tmp * x) ^ (tmp << 63 >> 63);
}
