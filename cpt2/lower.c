//------------test case:

//------------code intro/design:

//------------main code

#include <stdio.h>
int main(int argc, char const *argv[])
{
    char temp;

    while ((temp = getchar()) != EOF)
    {

        if (temp >= 'A' && temp <= 'Z')
        {
            temp += 'a' - 'A';
        }
        putchar(temp);
    }

    return 0;
}