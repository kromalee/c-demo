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
        ++cc;
        if ('\n' == temp)
        {
            ++nl;
        }
        // 单词数不能记分隔符个数,连续分隔符会使单词数失效;
        if (temp == '\n' || temp == ' ' || temp == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }

        // c = getchar();
    }
    // printf("%ld\n", nc);
    printf("line-count:%d\n words-cout:%d\n char-count:%d\n", nl, wc, cc);
    system("pause");
    return 0;
}
