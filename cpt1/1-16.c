#include <stdio.h>
#define MAXLINE 10

int my_getline(char s[], int lim);
void my_strcpy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    int len;
    int maxLen;
    char line[MAXLINE];
    char longest[MAXLINE];

    maxLen = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {

        if (len > maxLen)
        {
            maxLen = len;
            my_strcpy(longest, line);
        }
    }

    if (maxLen > 0)
    {
        /* code */
        printf("%s\n", longest);
        printf("Max Len:%d", maxLen);
    }

    getchar();
    return 0;
}
int my_getline(char s[], int lim)
{
    int len = 0;
    // char *ptr = s;
    char temp;
    while ((temp = getchar()) != EOF && temp != '\n')
    {
        if (len < lim)
        {
            s[len] = temp;
        }
        ++len;
    }
    s[len] = '\0';

    return len;
}
void my_strcpy(char to[], char from[])
{
    char *ptrFrom = from;
    char *ptrTo = to;

    while ((*ptrFrom) != '\0')
    {
        *ptrTo = *ptrFrom;
        ++ptrFrom;
        ++ptrTo;
    }
    *ptrTo = '\0';
}
