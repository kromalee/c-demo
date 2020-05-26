#include <stdio.h>
#define MAXLINE 100
#define SHOW_MIN_LINE 10

int my_getline(char s[], int lim);
void my_strcpy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    int len;

    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
    {

        if (len > SHOW_MIN_LINE)
        {
            printf("%s\n", line);
        }
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
            // ++ptr;
        }

        ++len;
    }
    s[len] = 0;

    return len;
}
