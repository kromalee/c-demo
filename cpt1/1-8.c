#include <stdio.h>
#include <windows.h>
int main(int argc, char const *argv[])
{
    int ctab = 0;
    int cl = 0;
    int cspac = 0;
    char temp;
    while (((temp = getchar()) != EOF))
    {
        if ((temp == '\t'))
        {
            ++ctab;
        }

        if (temp == '\n')
        {
            ++cl;
        }

        if (temp == ' ')
        {
            /* code */
            ++cspac;
        }
    }
    printf("tab count:%d\n", ctab);
    printf("\\n count:%d\n", cl);
    printf("space count:%d\n", cspac);
    system("pause");
    return 0;
}