#include <stdio.h>
#define MAXLINE 100
#define SHOW_MIN_LINE 1

int myGetline(char s[], int lim);
int myRemove(char s[], int len);
int getLength(char s[]);
void myReverse(char s[]);

int main(int argc, char const *argv[])
{
    int len;

    char line[MAXLINE];

    while ((len = myGetline(line, MAXLINE)) > 0)
    {
        len = myRemove(line, len);
        myReverse(line);
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
void myReverse(char s[])
{
    //先获取长度
    int len = getLength(s);
    //遍历一半交换
    int i;
    char temp;
    for (i = 0; i < len / 2; i++)
    {
        // s[i] ^= s[len - 1 - i] ^= s[i] ^= s[len - 1 - i];
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
int getLength(char s[])
{
    int len = 0;
    while (s[len] != 0)
    {
        ++len;
    }
    printf("%d\n", len);
    return len;
}