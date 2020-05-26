//------------test case:

//------------code intro/design:

//------------main code

#include <stdio.h>
#define STR_LEN_MAX 6
enum
{
    NO,
    YES
};
int htoi(char s[]);
int main(int argc, char const *argv[])
{
    char s[STR_LEN_MAX] = "0x16f";
    printf("%x", htoi(s));

    return 0;
}
int htoi(char s[])
{
    int i = 0;
    int result = 0;
    int hexdigit; //每位数值
    int inhex;    //进位标记
                  //第1,2位要单独处理,不能在循环处理,因为循环里可能也有相同的非法值
    if (s[i] == '0')
    {
        ++i;

        if ((s[i] == 'x' || s[i] == 'X'))
        {
            ++i;
        }
    }

    inhex = YES;

    for (; inhex == YES; i++)
    {

        if (s[i] >= '0' && s[i] <= '9')
        {
            hexdigit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            hexdigit = 10 + (s[i] - 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            hexdigit = 10 + (s[i] - 'A');
        }
        else
        {
            inhex = NO;
        }

        if (inhex == YES)
        {
            result = result * 16 + hexdigit;
        }
    }

    // int numChar = 10;

    // ^(0(x | X)) ? ([a - f] | [A - F] | [0 - 9]) +
    // while (s[i] != 0)
    // {
    //     if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
    //     {
    //         ++i;
    //     }
    //     else if (s[i] >= '0' && s[i] <= '9')
    //     {
    //         result = result * 16 + (s[i] - '0'); //代码冗余------------------------------
    //     }
    //     else if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
    //     {

    //         while (numChar < s[i] - 'a' + 10)
    //         {
    //             numChar++;
    //         }
    //         result = result * 16 + numChar; //代码冗余------------------------------
    //         numChar = 10;
    //     }
    //     else
    //     {
    //         printf("unlegal data");
    //         return -1;
    //     }
    //     i++;
    // }
    return result;
}