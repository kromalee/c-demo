#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    //data
    double fah, cel;
    int lower, upper, step;

    //init
    lower = 0;
    step = 20;
    upper = 300;

    //algo
    fah = lower;
    while (fah <= upper)
    {
        /* code */
        cel = (5.0 / 9.0) * (fah - 32.0);
        printf("%3.0f\t%6.1f\n", fah, cel);
        fah += step;
    }

    return 0;
}