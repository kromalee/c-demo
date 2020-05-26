//------------test case:

//------------code intro/design:
// 顺序弄反了,s2中任一字符在字符串s1中出现的位置作为结果返回,如果s2中不包含s1中的字符,则返回-1;
//应该在s2中选字符与s1中遍历比较;
//------------main code

#include <stdio.h>

#define STR_MAX_LEN 100

int any(char s1[], char s2[]);
int main(int argc, char const *argv[])
{
    char s1[STR_MAX_LEN] = "ABCDEF";
    char s2[STR_MAX_LEN] = "F";
    ;
    printf("%d", any(s1, s2));
    return 0;
}
int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != 0; i++)
    {
        for (j = 0; s2[j] != 0; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}