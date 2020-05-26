//------------test case:

//------------code intro/design:
// 反向搜索 lastIndexOF实现
//------------main code

#include <stdio.h>
#include <string.h>

#define MAX_LINE 100
int my_getline(char s[], int lim);
int lastStrIndex(char s[], char t[]);

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

        if (lastStrIndex(line, pattern) >= 0)
        {
            printf("%s\n", line);
            found++;
        }
    }
    return found;
}
//find all lines matching pattern 反向
int lastStrIndex(char s[], char t[])
{
    //假装反向访问
    // int i, j, k;
    // int pos = -1; //记录最后一个位置
    // for (i = 0; s[i] != 0; i++)
    // {
    //     for (j = i, k = 0; s[j] == t[k] && t[k] != 0; j++, k++)
    //     {
    //         //nothing
    //     }
    //     if (k > 0 && t[k] == 0)
    //     {
    //         // return i;
    //         pos = i;
    //     }
    // }
    // return pos;

    //高效做法
    int i, j, k;
    for (i = strlen(s) - 1; i >= 0; i++)
    {
        //以下内容与正向查找相同
        for (j = i, k = 0; s[j] == t[k] && t[k] != 0; j++, k++)
        {
            //nothing
        }
        if (k > 0 && t[k] == 0)
        {
            return i;
        }
    }
    return -1;

    //真---反向访问 --内层遍历根本不需要反向
    // int i, j, k;
    // for (i = strlen(s) - 1; i >= 0; i--)
    // {

    //     for (j = i, k = strlen(t) - 1; s[j] == t[k] && k >= 0; j--, k--)
    //     {
    //         //nothing
    //     }
    //     //注意这里的第一个比较条件,无符号整型与int负数相比!!!
    //     if ((strlen(t) - 1 - k) > 0 && k == -1)
    //     {
    //         return strlen(s) - i;
    //     }
    // }
    // return -1;
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