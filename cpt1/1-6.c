#include <stdio.h>
int main(int argc, char const *argv[])
{
    int c;

    while (1)
    {
        /* code */
        //ctrl+z输入会变成0,其他情况都是1;
        printf("%d", (c = getchar()) != EOF);
    }

    return 0;
}
