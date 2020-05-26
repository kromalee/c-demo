//------------test case:

//------------code intro/design:
//find x in v[0]<=v[1]<=v[2]...<=v[n-1]
//------------main code

#include <stdio.h>
int binsearch(int x, int v[], int limit);

int main(int argc, char const *argv[])
{
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", binsearch(i, v, 10));
    }

    return 0;
}
//二分查找
//主要问题是边界处理
// 减少测试次数,没有思路?
//答案思路,把 第二次测试移动到循环中止条件的判断里,其实性能根本没有多少改进,反而可读性变差了!!!
int binsearch(int x, int v[], int limit)
{
    int lowIndex, highIndex, midIndex;
    lowIndex = 0, highIndex = limit - 1;
    do
    {
        midIndex = (lowIndex + highIndex) / 2;
        if (x < v[midIndex])
        {
            //因为已经比较过边界了,所以直接缩小一格范围,不然函数可能无法结束
            highIndex = midIndex - 1;
        }
        else
        {
            lowIndex = midIndex + 1;
        }
    } while (lowIndex <= highIndex && midIndex != x);

    if (midIndex == x)
    {
        return midIndex;
    }
    else
    {
        return -1;
    }
}