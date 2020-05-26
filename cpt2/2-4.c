//------------test case:

//------------code intro/design:
// 2-4.c ---delete all s2 *element from s1 *
//------------main code

#include <stdio.h>

#define STR_MAX_LEN 100

    void
    squeezeOneChar(char s[], char c);
void squeeze(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
    char s1[STR_MAX_LEN] = "ABCDEF";
    char s2[STR_MAX_LEN] = "ABF";
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}
void squeeze(char s1[], char s2[])
{
    int i;
    for (i = 0; s2[i] != 0; i++)
    {
        squeezeOneChar(s1, s2[i]);
    }
}
void squeezeOneChar(char s[], char c)
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