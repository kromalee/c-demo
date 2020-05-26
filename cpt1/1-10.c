#include <stdio.h>
//copy input to output 1st version
int main(int argc, char const *argv[])
{
    char c;
    // char last;
    // c = getchar();

    while ((c = getchar()) != EOF)
    {

        if ('\t' == c)
        {
            putchar('\\');
            putchar('t');
        }

        else if ('\b' == c)
        {
            putchar('\\');
            putchar('b');
        }
        else if ('\\' == c)
        {
            putchar('\\');
            putchar('\\');
        }

        else
        {
            putchar(c);
        }

        // last = c;
        // c = getchar();
    }

    return 0;
}
