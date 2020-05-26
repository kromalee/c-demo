//------------test case:

//------------code intro/design:
// 转为任意进制字符串

//------------main code

#include <stdio.h>
#include <string.h>
#define STR_MAX 100
void itoa(int n, char s[], int widthMin, int decimal);

void reverse(char str[]);

int main(int argc, char const *argv[])
{
    // 测试程序
    int a[3] = {-15, -15, 1234569870};
    char s[3][STR_MAX] = {};
    // itoa(a[0], s[0], 10);
    // printf("%s\n", s[0]);
    itoa(a[0], s[0], 10, 16);
    printf("%s\n", s[0]);

    itoa(a[1], s[1], 10, 8);
    printf("%s\n", s[1]);

    itoa(a[2], s[2], 10, 10);
    printf("%s\n", s[2]);

    return 0;
}
void itoa(int n, char s[], int widthMin, int decimal)
{
    int j = 0;
    unsigned int temp;
    int sign = 0;

    // 记录符号,并转为正数;
    if (n < 0)
    {
        sign = 1;
        temp = -n;
    }
    else
    {
        temp = n;
    }

    //循环从后往前取数
    j = 0;
    do
    {
        if (temp % decimal > 9)
        {
            //余数大于9的处理方式
            s[j] = temp % decimal - 10 + 'A';
        }
        else
        {
            s[j] = temp % decimal + '0';
        }
        j++;
        temp /= decimal;
    } while (temp > 0);

    //加八进制和十六进制特定格式
    if (decimal == 8)
    {
        s[j++] = '0';
    }
    else if (decimal == 16)
    {
        s[j++] = 'x';
        s[j++] = '0';
    }
    //处理符号
    if (sign == 1)
    {
        s[j++] = '-';
    }
    s[j] = 0;
    // 补空格(技巧:动态比较串长与定宽)
    for (; widthMin > strlen(s);)
    {
        s[j++] = ' ';
        s[j] = 0;
    }

    reverse(s);
}

//翻转字符串
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