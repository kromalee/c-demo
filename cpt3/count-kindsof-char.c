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
        switch (temp)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ndigits[temp - '0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
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
