//------------test case:

//------------code intro/design:
//indexOF()实现

//------------main code

#include <stdio.h>
#define MAX_LINE 100
int my_getline(char s[], int lim);
int strIndex(char s[], char t[]);

int main(int argc, char const *argv[])
{
    //测试grep
    char line[MAX_LINE];
    int found = 0;
    //当字符串为空时,啥也匹配不到
    char pattern[] = "ABC";
    // char pattern[] = "";

    while (my_getline(line, MAX_LINE) > 0)
    {

        if (strIndex(line, pattern) >= 0)
        {
            printf("%s\n", line);
            found++;
        }
    }
    return found;
}
//find all lines matching pattern
int strIndex(char s[], char t[])
{
    int i, j, k;
    // int flag;

    for (i = 0; s[i] != 0; i++)
    {
        // 代码简化,效率不变
        //匹配依据:一次某位置处的匹配中, pattern有部分匹配 且 pattern遍历结束

        //j访问s的子串,k访问pattern
        for (j = i, k = 0; s[j] == t[k] && t[k] != 0; j++, k++)
        {
            //nothing
        }
        //允许k=0 会给pattern为空时,给结果,这是不符合使用者逻辑的
        //
        if (k > 0 && t[k] == 0)
        {
            return i;
        }
    }

    // if (t[0] == s[i])s
    // {
    //     flag = 1;
    //     for (j = 1; t[j] != 0; j++)
    //     {

    //         if (t[j] != s[i + j])
    //         {
    //             flag = 0;
    //         }
    //     }

    //     if (flag == 1)
    //     {
    //         return i;
    //     }
    // }

    return -1;
}
//getline into s ,return length
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