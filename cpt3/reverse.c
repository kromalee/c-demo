//------------test case:

//------------code intro/design:

//------------main code

#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main(int argc, char const *argv[])
{
    char str[10] = "Hello";
    reverse(str);
    printf("%s", str);
    return 0;
}
//双索引翻转字符串

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