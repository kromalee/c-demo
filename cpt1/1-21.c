// testcase: a(7个空格) b(3个空格+1tab) c(3个空格) d


#include <stdio.h>

#define TABINC 8
int main(int argc, char const *argv[])
{
    int pos = 0; //当前位置,从0开始 与空格数计算有关,符合现实;
    char temp;
    int tabNeed = 0;
    int whiteNeed = 0;
    int tabCount = 0;
    int whiteCount = 0;

    while ((temp = getchar()) != EOF)
    {

        if (temp == ' ')
        {
            //遇到空格,并且不是制表符结束,需要空格
            if ((pos + 1) % TABINC != 0)
            {
                ++whiteNeed;
            }
            // 遇到空格,且制表符结束,则空格取消,换一个tab
            else
            {
                whiteNeed = 0;
                ++tabNeed;
            }
        }

        else
        {
            // 不是空格,先输出==积累的==tab和空格
            { //先输出积累的tab
                while (tabNeed > 0)
                {
                    putchar('\t');
                    ++tabCount;
                    --tabNeed;
                }
                //再检测tab,有tab就不需要空格了
                if (temp == '\t')
                { //这里只能输出积累值,因此不能在这里输出\t
                    whiteNeed = 0;
                }

                else //没有tab还需要输出积累的空格
                {
                    //输出小于8的空格
                    while (whiteNeed > 0)
                    {
                        putchar(' ');
                        --whiteNeed;
                        ++whiteCount;
                    }
                }
            }

            //又进入了正常检测并直接输出部分
            putchar(temp); // ----------------------------------------冗余代码合并
            if (temp == '\n')
            {
                // putchar('\n');// ------------------------------代码冗余,移到上面
                //回车则位置计0
                pos = 0;
            }

            else if (temp == '\t')
            {
                // putchar('\t');// ------------------------------代码冗余,移到上面
                pos = pos + (TABINC - (pos) % TABINC - 1);
                ++pos;
            }

            else
            {
                // 打印正常字符
                // putchar(temp);// ------------------------------代码冗余,移到上面
                ++pos;
            }
        }
    }

    return 0;
    // a       bb     ccc  ddddddddddddddddddddddd
}
// a
// a bbbb