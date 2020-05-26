//------------test case:

//------------code intro/design:
// !!!!!!屏蔽码思想:主要设计屏蔽码,
// !!!!!!对按位操作的功能不熟悉!!! (数字逻辑)

//此题题意较难理解:将x从第p位(第p位指从右开始计数向右数)     开始的n个位(右边n位)    设置为y中最右边n位的值,x的其余各位保持不变;
//------------main code

#include <stdio.h>

#define WORD_WIDTH 32

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int getbits(unsigned x, int p, int n);

int main(int argc, char const *argv[])
{
    printf("%d", setbits(0, 11, 4, 15));
    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{

    //!!!分析过程
    // xxx...xnnnx...xxx x
    // yyy...........nnn y

    //先把x的n清零(按位与屏蔽码);
    // xxx...xnnnx...xxx x
    //&111...10001...111 屏蔽码
    // xxx...x000x...xxx x中间结果
    //屏蔽码的设计,左移补零(不使用右移,因为右移补0与否跟实现有关)
    x &= ~((~((~0) << n)) << (p - n + 1));

    //把y中出最右边n位都清零并左移到第p位处;
    // yyy...........nnn y
    //&000...........111 屏蔽码
    // 000...........nnn
    // <<
    //=000...0nnn0...000 y最终结果
    y = (y & (~(~0 << n))) << (p - n + 1);

    //前两步OR操作;
    // xxx...x000x...xxx x中间结果
    //|000...0nnn0...000 y最终结果
    //=xxx...xnnnx...xxx x最终结果
    return x | y;
}
