#include <stdio.h>
#define MAXLINE 100
#define SHOW_MIN_LINE 1

int myGetline(char s[], int lim);
int myRemove(char s[], int len);

int main(int argc, char const *argv[])
{
    int len;

    char line[MAXLINE];

    while ((len = myGetline(line, MAXLINE)) > 0)
    {
        len = myRemove(line, len);
        if (len > SHOW_MIN_LINE)
        {
            printf("%s\nlength=%d\n", line, len);
        }
    }

    getchar();
    return 0;
}
int myGetline(char s[], int lim)
{
    int len = 0;
    // char *ptr = s;
    char temp;
    // int i;
    while ((temp = getchar()) != EOF && temp != '\n')
    {
        if (len < lim)
        {
            s[len] = temp;
            // ++ptr;
        }
        ++len;
    }

    s[len] = 0;

    return len;
}
int myRemove(char s[], int len)
{
    for (; len > 0; --len)
    {

        if (s[len - 1] != ' ' && s[len - 1] != '\t')
        {
            break;
        }

        else
        {
            s[len - 1] = '\0';
        }
    }
    return len;
}
