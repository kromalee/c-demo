//------------test case:

//------------code intro/design:
// expand 扩展缩写
//本质是把连接符替换成 中间的内容
//只针对ASCII字符
//需要注意控制下标不越界

//------------main code

#include <ctype.h>
#include <stdio.h>
#define STR_MAX 50
void expand(char des[], char full[]);
int main(int argc, char const *argv[])
{
    int i;
    char des[6][STR_MAX] = {"a-z", "0-9", "a-B-C", "a-z0-9", "-A-Z", "!-~"};
    char full[STR_MAX] = "";
    for (i = 0; i < 6; i++)
    {
        expand(des[i], full);
        printf("%s\n", full);
    }

    return 0;
}
void expand(char des[], char full[])
{
    int i, j;
    char k;
    full[0] = des[0];
    //只要从1开始就不会越界,0单独处理
    for (i = 1, j = 1; des[i - 1] != 0; i++)
    {

        if (des[i] == '-' && (des[i + 1] > des[i - 1]))
        {
            for (k = des[i - 1] + 1; k < des[i + 1]; ++k, ++j)
            {
                full[j] = k;
            }
        }
        else
        {
            full[j] = des[i];
            ++j;
        }
    }
    full[j] = 0;
}