//test case : EOF, enter,超出lim

#include <stdio.h>
#include <windows.h>
int main(int argc, char const *argv[])
{
    int i;
    const int lim = 10;
    char c;
    char s[lim];
    enum loop
    {
        NO,
        YES
    };
    enum loop okloop = YES;
    i = 0;
    //符合 && 的执行逻辑
    while (okloop == YES)
    {

        if (i >= lim - 1)
        {
            okloop = NO;
        }
        else if ((c = getchar()) == '\n')
        {
            okloop = NO;
        }
        else if (c == EOF)
        {
            okloop = NO;
        }
        else
        {
            s[i] = c;
            ++i;
        }
    }
    //结果正确,但判断逻辑不相同
    // for (i = 0; ((c = getchar()) != EOF); i++)
    // {
    //     if (c != '\n')
    //     {
    //         if (i >= lim - 1)
    //         {
    //             s[i] = c;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    printf("input over\n");
    for (i = 0; s[i] != 0; i++)
    {
        putchar(s[i]);
    }
    printf("\nget %d ", i);

    system("pause");
    return 0;
}
