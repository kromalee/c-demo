#include <stdio.h>
#include <windows.h>
//copy input to output 1st version
int main(int argc, char const *argv[])
{
    // int count;
    long nc = 0;
    // c = getchar();
    //windows中EOF必须独占一行 ,其他shell没问题
    while ((getchar()) != EOF)
    {
        // putchar(c);
        ++nc;

        // c = getchar();
    }
    printf("%ld\n", nc);
    system("pause");

    return 0;
}
