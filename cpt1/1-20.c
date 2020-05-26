// testcase:a       bbbb    cccccccc        ddddddddd
#include <stdio.h>

#define TABINC 8
int main(int argc, char const *argv[])
{
    int pos = 0;//当前位置,从0开始 与空格数计算有关,符合现实;
    int blockNeed = 0;
    char temp;
    int i;

    while ((temp = getchar()) != EOF)
    {

        if (temp == '\t')
        {
            blockNeed = TABINC - (pos) % TABINC;//由于取模最大值为7,8个字符时,应该直接打一个完整的tab
            for (i = 0; i < blockNeed; i++)
            {
                putchar(' ');
                ++pos;
            }
        }
        else if (temp == '\n')
        {
            putchar(temp);
            pos = 0;
        }
        else
        {
            putchar(temp);
            ++pos;
        }
    }

    return 0;
    // a       bb     ccc  ddddddddddddddddddddddd
}
// a
// a bbbb