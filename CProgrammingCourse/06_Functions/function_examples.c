/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates user-defined functions   *
*                with parameters, recursion, and use   *
*                of math library functions             *
* Created On   : 10th May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <math.h>

// User-defined function declarations
void printgreetmsg(void);
int sum(int num1, int num2);           // Call by value
void checkEvenOdd(int num);
void printNumber(int num);             // Recursive function

// Function definitions

void printgreetmsg(void)
{
    printf("Hello! Wishing you positivity and success today!\n");
}

int sum(int num1, int num2)
{
    return num1 + num2;
}

void checkEvenOdd(int num)
{
    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);
}

void printNumber(int num)
{
    if (num == 0)
        return;
    printNumber(num - 1);
    printf("%d\n", num);
}

int main(int argc, char *argv[])
{
    // Greeting messages
    printgreetmsg();
    printgreetmsg();

    // Using a library function
    double num = 49.0;
    printf("Built-in function: Square root of %.2f is %.2f\n", num, sqrt(num));

    // User-defined sum function
    int num1 = 10, num2 = 20;
    int sumoftwo = sum(num1, num2);
    printf("User-defined function: Sum = %d\n", sumoftwo);

    // Even or odd check
    checkEvenOdd(100);

    // Recursive function demonstration
    printf("Printing numbers using recursion:\n");
    printNumber(10);

    return 0;
}