#include <stdio.h>
#include <windows.h>
int main(int argc, char const *argv[])
{
    int lc = 0;
    char temp;
    while (((temp = getchar()) != EOF))
    {
        if ((temp == '\n'))
        {
            ++lc;
        }
    }
    printf("%d\n", lc);
    system("pause");
    return 0;
}