//------------test case:

//------------code intro/design:
// convert  n to characters in s*

//------------main code

#include <stdio.h>
#include <string.h>
#define STR_MAX 100
void itoa(int n, char s[]);

void reverse(char str[]);

int main(int argc, char const *argv[])
{
    //测试代码

    int a[3] = {0, -1, -2147483647 /*Min int +1 */};
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
    char tempS[STR_MAX] = "";
    if (n < 0)
    {
        s[i] = '-';
        ++i;
        n = -n;
    }
    //未考虑边界值 0 应该用do..while
    j = 0;
    do
    {
        tempS[j] = n % 10 + '0';
        j++;
        n /= 10;
    } while (n > 0);

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