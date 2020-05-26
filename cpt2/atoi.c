//------------test case:

//------------code intro/design:
//atoi
//------------main code
#define STR_LIM 12

long long my_atoi(char *str);

#include <stdio.h>
int main(int argc, char const *argv[])
{
    char str[STR_LIM] = "-2147483648"; //Min long long number
    char str2[STR_LIM] = "2147483647"; //Max --

    printf("%lld\n", my_atoi(str));
    printf("%lld\n", my_atoi(str2));

    return 0;
}
long long my_atoi(char *str)
{
    int i;
    int n = 0;
    int flag = 0;
    for (i = 0; str[i] != 0 && ((str[i] >= '0' && str[i] <= '9') || str[0] == '-'); i++)
    {
        if (str[i] == '-')
        {
            flag = 1;
        }
        else
        {
            n = 10 * n + (str[i] - '0');
        }
    }
    if (flag == 1)
    {
        return -n;
    }
    else
    {
        return n;
    }
}