//------------test case:

//------------code intro/design:
// rand() and srand()
//依赖seed 的循环更改
//------------main code
#include <stdio.h>
#include <time.h>

unsigned long int rand_seed;
void mySrand(unsigned int seed);
unsigned long int myRand();

int main(int argc, char const *argv[])
{
    int i;
    mySrand(time(NULL));

    for (i = 0; i < 100; i++)
    {

        printf("%lu ", myRand());
    }

    return 0;
}
void mySrand(unsigned int seed)
{
    rand_seed = seed;
}
unsigned long int myRand()
{

    //迭代取中法 0-32767
    // rand_seed = rand_seed * 1103515245 + 12345;
    // return (unsigned int)(rand_seed / 65536) % 32768;

    //乘同余法

    //线性同余法/混合同余法
    //     线性同余算法有m 、a 、c 和X0 4个参数,通过置Xn + 1 ≡(aXn + c) (mod m) ,求得随机数序列< Xn > , 这个序列称作线性同余序列。m、a 、c 和X0 分别称做模数、乘数、增量和初始值。线性同余方法速度快,如果对乘数和模数进行适当的选择,可以满足用于评价一个随机数产生器的3 种准则:
    // 1.这个函数应该是一个完整周期的产生函数。也就是说,这个函数应该在重复之前产生出0 到m之间的所有数;
    // 2.产生的序列应该看起来是随机的;
    // 3.这个函数应该用32bit 算术高效实现

    return rand_seed = (rand_seed * 16807L) % ((1UL << 31) - 1);

    // return (rand_seed * 31 + 13) % ((1 << 15) - 1);
}