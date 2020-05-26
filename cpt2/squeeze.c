//------------test case:

//------------code intro/design:
// squeeze.c ---delete all c from s*
//------------main code

#include <stdio.h>
#define STR_MAX_LEN 100
void squeeze(char s[], char c);
int main(int argc, char const *argv[])
{
    char s[STR_MAX_LEN] = "ABCDEB";
    squeeze(s, 'B');
    printf("%s", s);
    return 0;
}
void squeeze(char s[], char c)
{
    int i, j;
    for (i = j = 0; s[i] != 0; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = 0;
}