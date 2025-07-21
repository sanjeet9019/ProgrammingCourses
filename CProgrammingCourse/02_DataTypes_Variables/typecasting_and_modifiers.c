/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates C data modifiers like  *
*                 signed, unsigned, short, and long   *
*                 long int using typedefs from a      *
*                 custom header file. Also showcases  *
*                 implicit and explicit typecasting.  *
* Created On    : 19th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include <stdio.h>
#include "Cmodifiers.h"

int main(int argc ,char *argv[])
{
   signed int num1 = 4;               // 4 bytes: can hold positive and negative
   unsigned int num2 = 23432;         // only positive values
   SHORT num3 = 3424;                 // defined in header: short int (2 bytes)
   LLINT num4 = 1324235255;           // defined in header: long long int (8 bytes)

   printf("size of int num1 = %ld bytes\n", sizeof(num1));
   printf("SHORT num3 = %d\n", num3);
   printf("LLINT num4 = %lld\n", num4); // Use %lld for long long int
   printf("Unsigned num2 = %u\n", num2);

   int a = 10;
   float result = 10 / 3;             // implicit typecasting: int divided by int, then assigned to float
   printf("Implicit typecasting result = %0.2f\n", result);

   float result1 = (float)10 / 3;     // explicit typecasting: forces float division
   printf("Explicit typecasting result = %0.2f\n", result1);

   return 0;
}
