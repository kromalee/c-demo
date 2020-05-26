//------------test case:

//------------code intro/design:
//希尔排序
//------------main code

#include <stdio.h>
void shellsort(int v[], int n);

int main(int argc, char const *argv[])
{

    int v[5] = {0, 1, 2, 3, 4};
    int i;
    shellsort(v, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}

//不带监视哨的希尔排序实现
void shellsort(int v[], int n)
{
    int i, j, d, temp;
    for (d = n / 2; d > 0; d /= 2)
    {

        for (i = d; i < n; i++)
        {
            for (j = i - d; j >= 0 && v[j] < v[j + d]; j -= d)
            {
                temp = v[j];
                v[j] = v[j + d];
                v[j + d] = temp;
            }
        }
    }
}