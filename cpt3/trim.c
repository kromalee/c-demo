//------------test case:

//------------code intro/design:
//删除字符串尾部的空格符,制表符和换行符

//------------main code

#include <stdio.h>
#include <string.h>
#define STR_MAX 100
void trim(char s[]);

int main(int argc, char const *argv[])
{
    char s[STR_MAX] = "\n";
    printf("%s", s);

    trim(s);
    printf("%s", s);
    return 0;
}
void trim(char s[])
{
    int i;

    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
        {
            break;
        }
    }
    s[i + 1] = 0;
}