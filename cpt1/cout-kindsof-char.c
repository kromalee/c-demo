#include <stdio.h>
int main(int argc, char const *argv[])
{
    char temp;
    int i; //循环输出的index
    int nwhite, nother;
    int ndigits[10] = {0};
    nother = nwhite = i = 0;

    while ((temp = getchar()) != EOF)
    {
        if (temp >= '0' && temp <= '9')
        {
            ++ndigits[temp - '0'];
        }
        else if (' ' == temp)
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("%c count:%d\n", '0' + i, ndigits[i]);
    }
    printf("white space count:%d\n others count: %d", nwhite, nother);
    getchar();
    return 0;
}
