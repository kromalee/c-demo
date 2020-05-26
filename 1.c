//如果没有键盘输入程序一直输出Hello World，直到用户按Esc结束
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void)
{
    char ch;
    while (ch != 27)
    {
        printf("HelloWorld\n");
        if (kbhit())
            ch = getch();
    }
    printf("End!\n");
    system("pause");
    return 0;
}