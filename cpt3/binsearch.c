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
int binsearch(int x, int v[], int limit)
{
    int lowIndex, highIndex, midIndex;
    lowIndex = 0, highIndex = limit - 1;

    while (lowIndex <= highIndex)
    {
        midIndex = (lowIndex + highIndex) / 2;
        if (x < v[midIndex])
        {
            //因为已经比较过边界了,所以直接缩小一格范围,不然函数可能无法结束
            highIndex = midIndex - 1;
        }
        else if (x > v[midIndex])

        {
            lowIndex = midIndex + 1;
        }
        else
        {
            return midIndex;
        }
    }
    return -1;
}