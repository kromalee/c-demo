//------------test case:
// rightbot(1,1) --> pow(2,31)
//------------code intro/design:
//循环右移  与机器字长有关;
//---求机器字长;
//!!!答案的实现中,未考虑有些机器右移补1造成后果,附近的题都未考虑符号;
//------------main code

#include <math.h>
#include <stdio.h>
int wordLength(void);
unsigned int rightrot(unsigned int x, int n);
int main(int argc, char const *argv[])
{
    printf("%u\n", rightrot(1, 1));
    // printf("%f\n", pow(2, 31));
    return 0;
}
unsigned int rightrot(unsigned int x, int n)
{
    unsigned int rbit;
    //可以不用循环--------------------------------------------------------------------------如下
    // while (n-- > 0)
    // {
    //     //
    //     rbit = (x & 1) << (wordLength() - 1);
    //     x = x >> 1;
    //     x = x | rbit;
    //     }
    //-------------------------------------------------------------------------------------here

    if ((n = n % wordLength()) > 0)
    {
        rbit = (x & 1) << (wordLength() - 1);
        x = x >> 1;
        x = x | rbit;
    }

    return x;
}
int wordLength(void)
{
    int i;
    //求字长;
    unsigned int temp = 0;
    temp = ~temp;

    for (i = 1; (temp = (temp << 1)) > 0; i++)
    {
        /* nothing */
    }
    // printf("word width(unsigned int) %d bit\n", i);
    return i;
}
