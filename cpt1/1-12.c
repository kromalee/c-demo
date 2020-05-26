#include <stdio.h>
#include <windows.h>
#define IN 1
#define OUT 0
int main(int argc, char const *argv[])
{
    //count lines ,words,characters in input;
    int temp;
    int nl, wc, cc;
    int state;

    nl = wc = cc = 0;
    state = OUT;

    while ((temp = getchar()) != EOF)
    {
        // ++cc;
        // if ('\n' == temp)
        // {
        //     putchar('\n');
        //     ++nl;
        //     continue;
        // }
        // // 单词数不能记分隔符个数,连续分隔符会使单词数失效;
        // if (temp == '\n' || temp == ' ' || temp == '\t')
        // {
        //     state = OUT;
        //     continue;
        // }
        // else if (state == OUT)
        // {
        //     putchar('\n');
        //     state = IN;
        //     ++wc;
        // }
        // putchar(temp);
        // 逻辑错误 原因:太依赖旧程序,没有独立思考 ;

        if (temp == ' ' || temp == '\t' || temp == '\n')
        {
            if (state == IN)
            {
                putchar('\n');
                state = OUT;
            }
        }
        else if (state == OUT)
        {
            state = IN;
            putchar(temp);
        }

        else
        {
            putchar(temp);
        }

        // c = getchar();
    }
    // printf("%ld\n", nc);
    printf("line-count:%d\n words-cout:%d\n char-count:%d\n", nl, wc, cc);
    system("pause");
    return 0;
}
