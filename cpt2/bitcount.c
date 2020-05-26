//------------test case:

//------------code intro/design:
//注意左移操作属于不改源操作,必须用返回值接收

//------------main code

#include <stdio.h>
int bitcount(unsigned int x);

int main(int argc, char const *argv[])
{
    printf("%d", bitcount(7));

    return 0;
}
int bitcount(unsigned int x)
{
    int i;

    for (i = 0; x != 0; x >>= 1)
    {

        if (x & 1)
        {
            ++i;
        }
    }
    return i;
}