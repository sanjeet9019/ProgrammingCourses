/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates advanced function usage  *
*                including inline, variadic, and       *
*                standard functions in C               *
* Created On   : 22nd May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <stdarg.h>  // For variadic functions: va_list, va_start, va_arg, va_end

// 🚀 Function declarations
int cubeNormal(int n);                    // Regular function
inline int cubeInline(int n);            // Inline function
void printNumber(int a, int b, int c, int d);  // Fixed-parameter function
void printNumbervar(int count, ...);     // Variadic function

// ✳️ Inline function: computes cube using (n * n * n)
inline int cubeInline(int n)
{
    return n * n * n;
}

// ✳️ Regular cube function using volatile variables
int cubeNormal(int n)
{
    volatile int x = n;
    volatile int y = x * x;
    volatile int z = y * x;
    return z;
}

// ✳️ Function with fixed arguments
void printNumber(int a, int b, int c, int d)
{
    printf("Fixed-arg function: %d %d %d %d\n", a, b, c, d);
}

// ✳️ Variadic function: accepts variable number of integers
void printNumbervar(int count, ...)
{
    va_list param;
    va_start(param, count);

    for (int i = 0; i < count; i++)
    {
        int data = va_arg(param, int);
        printf("Variadic arg %d = %d\n", i + 1, data);
    }

    va_end(param);
}

// 🧪 Driver code
int main(int argc, char *argv[])
{
    // 🔹 Test normal cube
    printf("Normal Cube of 4     = %d\n", cubeNormal(4));

    // 🔹 Test inline cube
    printf("Inline Cube of 4     = %d\n", cubeInline(4));

    // 🔹 Test fixed-arg function
    printNumber(3, 10, 20, 30);

    // 🔹 Test variadic functions
    printNumbervar(3, 77, 88, 99);
    printNumbervar(4, 66, 77, 88, 99);

    return 0;
}