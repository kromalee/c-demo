#include <stdio.h>
#include <windows.h>
#define IN 1
#define OUT 0
// 直方图绘制限制
//直方图自变量限制
#define WORD_LENGTH_MAX 10
#define WORD_LENGTH_MIN 1
// 直方图因变量限制
#define WORD_LENGTH_COUNT_MAX 20

//水平直方图元素
#define PLANT_BLANK "\t"
#define LINE_HEAD      "        "
#define LINE_HEAD_LAST "wordLen:"

int main(int argc, char const *argv[])
{
    //count lines ,words,characters in input;
    char temp;
    int state;
    int wl;                                           //单词长度
    int i, j;                                         //循环计数
    int wordLengthCounter[WORD_LENGTH_MAX + 1] = {0}; //结果存储数组
    state = OUT;
    wl = 0;
    while ((temp = getchar()) != EOF)
    {

        if (temp == '\n' || temp == ' ' || temp == '\t')
        {

            if (state == IN)
            {
                //溢出则算最大长度;
                if (wl >= WORD_LENGTH_MAX)
                {
                    ++wordLengthCounter[WORD_LENGTH_MAX];
                }

                wordLengthCounter[wl]++;
                wl = 0;
                //单词结束
                state = OUT;
            }
        }

        else if (state == OUT)
        {
            // 单词开始
            state = IN;
            ++wl;
        }
        else
        {
            //单词中
            ++wl;
        }
    }
    // test
    // for (i = WORD_LENGTH_MIN; i <= WORD_LENGTH_MAX; i++)
    // {
    //     printf("%d\t", wordLengthCounter[i]);
    // }

    //vertical直方图绘图
    for (i = 1; i <= WORD_LENGTH_MAX; i++)
    {
        printf("Wrd.Length%2d:", i);
        for (j = 0; j < wordLengthCounter[i]; j++)
        {
            printf("#");
        }
        printf(" %d\n", wordLengthCounter[i]);
    }

    //palne直方图绘图

    for (i = 0; i < WORD_LENGTH_COUNT_MAX; i++)
    {
        printf(LINE_HEAD);
        for (j = 1; j <= WORD_LENGTH_MAX; j++)
        {
            // 数值+间隔
            printf(PLANT_BLANK);
            if (wordLengthCounter[j] >= WORD_LENGTH_COUNT_MAX - i)
            {
                printf(" #");
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    //打印直方图的坐标
    printf(LINE_HEAD_LAST);
    for (j = 1; j <= WORD_LENGTH_MAX; j++)
    {
        // 数值+间隔
        printf(PLANT_BLANK);
        printf("%2d", j);
    }
    printf("\n");

    system("pause");
    return 0;

    //test case
    /*
    a b c
    a bb ccc
    aa aa bbb bbb bbb bbb ccccc ccccc cccccc ddddddddddddddddddddddddddddddd
    */
}
