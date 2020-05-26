//------------test case:

//------------code intro/design:
//string 类型转为双精度浮点数

//------------main code

#include <ctype.h>
#include <math.h>
#include <stdio.h>

double my_atof(char str[]);

int main(int argc, char const *argv[])
{
    //测试用例
    printf("%f\n", my_atof("2.8"));
    printf("%f\n", my_atof("+2.8"));
    printf("%f\n", my_atof("-2.8000000000000000000"));
    printf("%f\n", my_atof(".8"));
    printf("%f\n", my_atof("2."));
    printf("%f\n", my_atof("0"));

    return 0;
}

double my_atof(char str[])
{
    int i = 0;
    double val, power; //数值和指数
    // double result = 0;
    // double floatPos = 0;
    int sign = 1;
    val = 0;
    power = 1;

    //化简符号处理
    sign = (str[i] == '-') ? -1 : 1;

    if (str[i] == '-' || str[i] == '+')
    {
        ++i;
    }

    for (; isdigit(str[i]); i++)
    {
        val = val * 10.0 + str[i] - '0';
    }

    if (str[i] == '.')
    {
        ++i;
    }
    for (; isdigit(str[i]); i++)
    {
        val = val * 10.0 + str[i] - '0';
        power *= 10;
    }
    return sign * val / power;
    // if (str[0] == '-')
    // {
    //     sign = -1;
    //     ++i;
    // }
    // else if (str[0] == '+')
    // {
    //     sign = 1;
    //     ++i;
    // }

    //不考虑输入错误的情况
    //我是直接切分字符串
    //不符合存储本质,应分为小数部分和指数部分处理
    //两重循环,复杂度过高;
    // for (; str[i] != 0;)
    // {

    //     for (; isdigit(str[i]); i++)
    //     {
    //         result = result * 10.0 + str[i] - '0';
    //     }
    //     ++i; //跳过小数点
    //     for (floatPos = 1; isdigit(str[i]); i++, floatPos++)
    //     {
    //         result = result + (str[i] - '0') * pow(10, -floatPos);
    //     }w
    // }
    // return result;
}