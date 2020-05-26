#include <stdio.h>
#define LOWER 0
#define STEP 20
#define UPPER 300

int main(int argc, char const *argv[])
{
    /* code */
    //data
    double fah, cel;
    // int LOW #defineER, UPPER, STEP;

    //init

    //algo
    // fah = LOWER;
    // while (fah#define <= UPPER)
    // {
    //     /* code */
    //     cel = (5.0 / 9.0) * (fah - 32.0);
    //     printf("%3.0f\t%6.1f\n", fah, cel);
    //     fah += STEP;
    // }

    for (fah = LOWER; fah <= UPPER; fah += STEP)
    {
        /* code */
        printf("%3.0f\t%6.1f\n", fah, (5.0 / 9.0) * (fah - 32.0));
    }

    return 0;
}