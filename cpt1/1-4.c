#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    //data
    double fah, cel;
    int lower, upper, step;

    //init
    lower = -20;
    step = 10;
    upper = 150;

    //algo
    printf("cel-fah table\n");
    cel = lower;
    while (cel <= upper)
    {
        /* code */
        // cel = (5.0 / 9.0) * (fah - 32.0);
        fah = cel * (9.0 / 5.0) + 32.0;
        printf("%6.1f\t%3.0f\n", cel, fah);
        cel += step;
    }
    getchar();
    return 0;
}