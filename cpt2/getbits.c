//------------test case:

//------------code intro/design:
// get n bits from position p
//------------main code

#include <stdio.h>
unsigned int getbits(unsigned x, int p, int n);

int main(int argc, char const *argv[])
{

    int i;
    int n = 3;

    for (i = 0; i < n; i++)
    {
        //利用现成的函数取一位输出!!
        printf("%d", getbits(getbits(10, 4, n), 2 - i, 1));
    }

    return 0;
}
unsigned int getbits(unsigned x, int p, int n)
{
    //     这里以 x = 10 作为举例，运算过程如下
    // 返回x中从右边数第p位开始向右数n位的字段
    // getbits(10, 4, 3) = 2

    // 10  0000 0000 0000 1010 |
    // >>p 0000 0000 0000 0000 | 1010
    // >>1 0000 0000 0000 0000 | 0101 0
    // <<n 0000 0000 0000 0010 | 10

    // ~0  1111 1111 1111 1111 |
    // <<n 1111 1111 1111 1000 |
    // ~   0000 0000 0000 0111 |

    // &   0000 0000 0000 0010 -> 2
    return (x >> (p + 1 - n)) & ~(~0 << n);
}