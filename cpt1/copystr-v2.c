#include <stdio.h>
//copy input to output 1st version
int main(int argc, char const *argv[])
{
    int c;
    // c = getchar();

    while ((c=getchar()) != EOF)
    {
        putchar(c);
        // c = getchar();
    }

    return 0;
}
