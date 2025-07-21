/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates the use of sizeof        *
*                keyword in C to calculate memory      *
*                occupied by data types and variables. *
*                Includes byte-bit conversion and      *
*                array size evaluations.               *
* Created On   : 22nd May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <math.h>

#define BYTETOBITS 8  // 1 Byte = 8 Bits

int main(int argc, char *argv[])
{
    // 🔹 Primitive Data Types
    int a = 10;       // Expected: 4 bytes
    char ch = 'A';    // Expected: 1 byte
    float pi = 3.14;  // Expected: 4 bytes

    printf("--- Primitive Data Type Sizes ---\n");
    printf("Size of int      = %d bytes (%d bits)\n", sizeof(int), sizeof(int) * BYTETOBITS);
    printf("Size of char     = %d bytes (%d bits)\n", sizeof(char), sizeof(char) * BYTETOBITS);
    printf("Size of float    = %d bytes (%d bits)\n", sizeof(float), sizeof(float) * BYTETOBITS);
    printf("Size of double   = %d bytes (%d bits)\n\n", sizeof(double), sizeof(double) * BYTETOBITS);

    // 🔹 Variable Sizes
    printf("--- Variable Sizes ---\n");
    printf("Size of variable int a     = %d bytes (%d bits)\n", sizeof(a), sizeof(a) * BYTETOBITS);
    printf("Size of variable char ch   = %d bytes (%d bits)\n", sizeof(ch), sizeof(ch) * BYTETOBITS);
    printf("Size of variable float pi  = %d bytes (%d bits)\n\n", sizeof(pi), sizeof(pi) * BYTETOBITS);

    // 🔹 Array and Derived Type
    int student[5]; // 5 elements of int

    printf("--- Array Size Analysis ---\n");
    printf("Size of int array student[5] = %d bytes (%d bits)\n", sizeof(student), sizeof(student) * BYTETOBITS);

    // Array length = Total size / size of one element
    int sizeArray = sizeof(student) / sizeof(int);
    printf("Total number of elements in student[] = %d\n", sizeArray);

    return 0;
}