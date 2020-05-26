//------------test case:

//------------code intro/design:
//注意左移操作属于不改源操作,必须用返回值接收

//------------main code

#include <stdio.h>
int bitcount(unsigned int x);
int main(int argc, char const *argv[])
{
    return bitcount(7);
}
int bitcount(unsigned int x)
{
    int i;

    for (i = 0; x > 0; x &= (x - 1), ++i)
        ;
    return i;
}