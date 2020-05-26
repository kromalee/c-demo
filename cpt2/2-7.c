//------------test case:

//------------code intro/design:

//------------main code

#include <stdio.h>
unsigned int invert(unsigned int x, int p, int n);
int main(int argc, char const *argv[])
{
    printf("%d", invert(0, 2, 1));

    return 0;
}
unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}