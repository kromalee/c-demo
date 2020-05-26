//------------test case:

//------------code intro/design:

//------------main code

#include <stdio.h>
void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int main(int argc, char const *argv[])
{
    char s[100] = "";
    char t[100] = "AB\tCD\n";
    char r[100] = "";
    printf("%s\n", t);
    escape(s, t);
    printf("%s\n", s);
    unescape(r, s);
    printf("%s\n", r);
    return 0;
}
void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    for (i = 0; t[i] != 0; ++i, ++j)
    {
        switch (t[i])
        {
        case '\n':
            s[j] = '\\';
            s[++j] = 'n';
            break;
        case '\t':
            s[j] = '\\';
            s[++j] = 't';
            break;

        default:
            s[j] = t[i];
            break;
        }
    }
    s[j] = 0;
}
void unescape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    for (i = 0; t[i] != 0; ++i, ++j)
    {
        switch (t[i])
        {
        case '\\':

            if (t[i + 1] == 'n')
            {
                s[j] = '\n';
                ++i;
                break;
            }
            else if (t[i + 1] == 't')
            {
                s[j] = '\t';
                ++i;
                break;
            }
            else
            {
                ;
            }

        default:
            s[j] = t[i];
            break;
        }
    }
    s[j] = 0;
}