//------------test case:

//------------code intro/design:
// convert s to int :version 2;

//------------main code
#define STR_LIM 11
#include <ctype.h>
#include <stdio.h>
long long my_atoi(char str[]);

int main(int argc, char const *argv[])
{
    char str[STR_LIM] = "-2147483648"; //Min long long number
    char str2[STR_LIM] = "2147483647"; //Max --

    printf("%lld\n", my_atoi(str));
    printf("%lld\n", my_atoi(str2));

    return 0;
}
long long my_atoi(char str[])
{
    int i, n, sign;
    n = 0;
    for (i = 0; isspace(str[i]); i++)
    {
        ;
    }
    sign = (str[i] == '-' ? -1 : 1);

    if (str[i] == '+' || str[i] == '-')
    {
        ++i;
    }

    for (; isdigit(str[i]); i++)
    {
        n = n * 10 + str[i] - '0';
    }
    return sign * n;
}