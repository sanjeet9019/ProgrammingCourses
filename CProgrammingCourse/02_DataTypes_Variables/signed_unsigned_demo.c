/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates signed vs unsigned types *
*                using char, int, and overflow behavior*
* Created On   : 9th May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    char ch = 10;  // Without quotes: numeric value
    printf("Value of char ch as number = %d\n", ch);

    signed char num1 = 7;
    printf("Signed char +ve = %d\n", num1);

    num1 = -7;
    printf("Signed char -ve = %d\n", num1);

    unsigned char num2 = 10;
    printf("Unsigned char = %u\n", num2);

    num2 = -1;  // Wraps to 255
    printf("Unsigned char -1 = %u\n", num2);

    num2 = -10;  // Wraps to 246
    printf("Unsigned char -10 = %u\n", num2);

    // Overflow demonstration
    unsigned char bignum = 260;  // Wraps to 4
    printf("Unsigned overflow (260) = %u\n", bignum);

    ch = 'A';
    printf("Char literal = %c\n", ch);
    printf("Char ASCII = %d\n", ch);

    signed int num5 = 10;
    printf("Signed int = %d\n", num5);

    unsigned int unum = 1003;
    printf("Unsigned int = %u\n", unum);

    return 0;
}