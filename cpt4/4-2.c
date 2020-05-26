//------------test case:

//------------code intro/design:
//带科学计数法的atof实现
//与答案有小差异的另一种做法

//------------main code

#include <ctype.h>
#include <math.h>
#include <stdio.h>
double my_atof(char str[]);
int main(int argc, char const *argv[])
{
    //测试用例
    // printf("%f\n", my_atof("2.8"));
    // printf("%f\n", my_atof("+2.8"));
    // printf("%f\n", my_atof("-2.8000000000000000000"));
    // printf("%f\n", my_atof(".8"));
    // printf("%f\n", my_atof("2."));
    // printf("%f\n", my_atof("0"));
    printf("%e\n", my_atof("123.45e-6"));

    return 0;
}
double my_atof(char str[])
{
    double val = 0;
    double power = 1;
    double sign = 1;
    int i = 0;
    double exp = 0;

    if (str[i] == '-')
    {
        sign = -1;
        ++i;
    }

    else if (str[i] == '+')
    {
        sign = 1;
        ++i;
    }

    for (; isdigit(str[i]); i++)
    {
        val = val * 10 + str[i] - '0';
    }

    if (str[i] == '.')
    {
        ++i;
    }

    for (; isdigit(str[i]); i++)
    {
        val = val * 10 + str[i] - '0';
        power *= 10;
    }
    // 中间过渡结果
    val = sign * val / power;
    printf("%e\n", val);

    //此时sign表示指数的正负
    sign = 1;
    if (str[i] == 'e' || str[i] == 'E')
    {
        ++i;
    }

    if (str[i] == '-')
    {
        sign = -1;
        ++i;
    }

    else if (str[i] == '+')
    {
        sign = 1;
        ++i;
    }

    for (; isdigit(str[i]); i++)
    {
        exp = exp * 10 + str[i] - '0';
    }

    //处理最后结果

    if (sign == 1)
    {

        while (exp-- > 0)
        {
            val *= 10;
        }
    }
    else
    {

        while (exp-- > 0)
        {
            val /= 10;
        }
    }
    return val;
    return val * pow(10, sign * exp);

    //完全非拼接处理方式,设定太多的标记变量

    // double num = 0;
    // int exponent = 0;
    // int exponent_before = 0;
    // int sign = 1;
    // int i = 0;
    // int flag_dot = 0;
    // int flag_science_notation = 0;
    // int exponent_sign = 1;
    // //开头负号
    // sign = (str[0] == '-') ? -1 : 1;
    // if (str[0] == '-')
    // {
    //     i++;
    // }
    // for (; str[i] != 0; i++)
    // {
    //     //数值
    //     if (isdigit(str[i]))
    //     {

    //         //在E之后
    //         if (flag_science_notation == 1)
    //         {
    //             exponent = exponent * 10 + (str[i] - '0');
    //         }
    //         //在E之前
    //         else
    //         {
    //             num = num * 10 + (str[i] - '0');
    //             //小数点之后
    //             if (flag_dot == 1)
    //             {
    //                 exponent_before++;
    //             }
    //         }
    //     }
    //     //小数点
    //     else if (str[i] == '.')
    //     {
    //         flag_dot = 1;
    //     }
    //     //科学记数法符号
    //     else if (str[i] == 'e' || str[i] == 'E')
    //     {
    //         flag_science_notation = 1;
    //     }
    //     //科学计数法中的负号
    //     else if (str[i] == '-')
    //     {
    //         exponent_sign = -1;
    //     }
    // }

    // return sign * num * pow(10, -exponent_before + exponent_sign * exponent);
}