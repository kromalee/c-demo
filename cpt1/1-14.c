#include <stdio.h>
#include <windows.h>
#define IN 1
#define OUT 0
// 直方图绘制限制
//直方图自变量限制
#define CHAR_ASCII_MIN 97
#define CHAR_ASCII_MAX 122
// 直方图因变量限制
#define ASCII_FREQUENCY_MAX 20

//水平直方图元素
#define PLANT_BLANK " "
#define LINE_HEAD "        "
#define LINE_HEAD_LAST "TheChar:"

int main(int argc, char const *argv[])
{
    //count lines ,words,characters in input;
    char temp;
    int i, j;                                                      //循环计数
    int asciiFrequency[CHAR_ASCII_MAX - CHAR_ASCII_MIN + 1] = {0}; //结果存储数组
    while ((temp = getchar()) != EOF)
    {

        for (i = 0; i < CHAR_ASCII_MAX - CHAR_ASCII_MIN + 1; i++)
        {
            //ascii码值比较
            if (CHAR_ASCII_MIN + i == (int)temp)
            {
                ++asciiFrequency[i];
            }
        }
    }
    // test
    // for (i = WORD_LENGTH_MIN; i <= WORD_LENGTH_MAX; i++)
    // {
    //     printf("%d\t", wordLengthCounter[i]);
    // }

    //palne直方图绘图
    for (i = 0; i < CHAR_ASCII_MAX - CHAR_ASCII_MIN + 1; i++)
    {
        printf(LINE_HEAD_LAST);
        printf("%c:", CHAR_ASCII_MIN + i);
        for (j = 0; j < asciiFrequency[i]; j++)
        {
            printf("#");
        }
        printf(" %d\n", asciiFrequency[i]);
    }

    //vertical直方图绘图
    for (i = 0; i < ASCII_FREQUENCY_MAX; i++)
    {
        printf(LINE_HEAD);
        for (j = 0; j < CHAR_ASCII_MAX - CHAR_ASCII_MIN + 1; j++)
        {
            // 数值+间隔
            printf(PLANT_BLANK);
            if (asciiFrequency[j] >= ASCII_FREQUENCY_MAX - i)
            {
                printf(" #");
            }

            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    //打印直方图的坐标
    printf(LINE_HEAD_LAST);
    for (j = 0; j < CHAR_ASCII_MAX - CHAR_ASCII_MIN + 1; j++)
    {
        // 数值+间隔
        printf(PLANT_BLANK);
        printf("%2c", j + CHAR_ASCII_MIN);
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
