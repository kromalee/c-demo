#include <float.h>
#include <limits.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{

    // printf("\tchar\tshort\tint\tlong");
    printf("the First way :use limits.h\n");

    printf("signed char: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("signed short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("signed long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);

    printf("unsigned char: %d ~ %d\n", 0, UCHAR_MAX);
    printf("unsigned short: %d ~ %d\n", 0, USHRT_MAX);
    printf("unsigned int: %d ~ %d\n", 0, UINT_MAX);
    printf("unsigned long: %d ~ %lu\n", 0, ULONG_MAX);
    //不用循环做,直接用数字的二进制本质,位运算解决;
    // printf("signed char:");

    // while (++now_temp > last_temp)
    // {
    //     last_temp = now_temp;
    // }
    // printf("%ld ~ %ld\n", -last_temp, last_temp);

    //运算规则 先取反,后截取,右移,然后转换为需要的类型
    printf("\nthe Second way :dont  use limits.h\n");

    printf("signed char: %d ~ %d\n", -(char)((unsigned char)~0 >> 1) - 1, (char)((unsigned char)~0 >> 1));
    printf("signed short: %d ~ %d\n", -(short)((unsigned short)~0 >> 1) - 1, (short)((unsigned short)~0 >> 1));
    printf("signed int: %d ~ %d\n", -(int)((unsigned int)~0 >> 1) - 1, (int)((unsigned int)~0 >> 1));
    printf("signed long : %lu ~ %lu\n", -(long)((unsigned long)~0 >> 1) - 1, (long)((unsigned long)~0 >> 1));

    printf("unsigned char: %u ~ %u\n", 0, (unsigned char)~0);
    printf("unsigned short: %u ~ %u\n", 0, (unsigned short)~0);
    printf("unsigned int : %u ~ %u\n", 0, (unsigned int)~0);
    printf("unsigned long: %u ~ %lu\n", 0, (unsigned long)~0);

    getchar();
    return 0;
}
