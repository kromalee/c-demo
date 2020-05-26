//------------test case:

//------------code intro/design:
// 数字转字符串

//------------main code

#include <stdio.h>
#include <string.h>
#define STR_MAX 100
void itoa(int n, char s[]);

void reverse(char str[]);

int main(int argc, char const *argv[])
{
    int a[3] = {0, -1, -2147483648 /*min int*/};
    char s[3][STR_MAX] = {};
    itoa(a[0], s[0]);
    printf("%s\n", s[0]);
    itoa(a[1], s[1]);
    printf("%s\n", s[1]);
    itoa(a[2], s[2]);
    printf("%s\n", s[2]);
    return 0;
}
void itoa(int n, char s[])
{
    int i = 0;
    int j = 0;
    //优化,在整数运算时保存为unsigned
    unsigned int temp;
    int sign = 0;
    char tempS[STR_MAX] = "";
    if (n < 0)
    {
        sign = 1;
        //优化,在整数运算时保存为unsigned
        temp = -n;
    }

    else
    {
        temp = n;
    }

    //未考虑边界值 0 应该用do..while
    j = 0;
    do
    {
        tempS[j] = temp % 10 + '0';
        j++;
        temp /= 10;
    } while (temp > 0);

    if (sign == 1)
    {
        // 取负号
        tempS[j++] = '-';
    }

    tempS[j] = 0;

    reverse(tempS);
    strcat(s, tempS);
}
void reverse(char str[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }
}