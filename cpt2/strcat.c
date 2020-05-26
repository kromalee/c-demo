//------------test case:

//------------code intro/design:
// concatenate t to end of s
//------------main code

#include <stdio.h>
#define STR_LEN_MAX 50
void myStrcat(char s[], char t[]);

int main(int argc, char const *argv[])
{
    char s[STR_LEN_MAX] = "ABCDE";
    char t[STR_LEN_MAX] = "FGHIJK";
    myStrcat(s, t)
    printf("%s\n", s);
    return 0;
}
void myStrcat(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != 0)
    {
        ++i;
    }

    while ((s[i++] = t[j++]) != 0)
        ;
}