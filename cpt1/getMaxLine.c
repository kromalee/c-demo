//test case:

#include <stdio.h>
#define MAXLINE 1000

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
        printf("%s", longest);
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
        s[len] = temp;
        ++len;
        // ++ptr;
    }
    s[len] = '\0';

    //字符数组的长度-1=字符串长度 一般字符串长度不计'\0'

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
}
