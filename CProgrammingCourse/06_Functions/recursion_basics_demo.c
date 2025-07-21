/*******************************************************
* *
* Author        : Sanjeet Prasad                       *
* Email         : sanjeet8.23@gmail.com                *
* Description   : Demonstrates basic C functions       *
*                 including declaration, definition,   *
*                 calling, and math.h usage. This file *
*                 also includes examples of recursive  *
*                 functions for sum of N numbers,      *
*                 factorial calculation, and printing  *
*                 numbers in sequence.                 *
* Created On    : 21st May 2025                        *
* Compiler      : GCC 14.2.0                           *
* Standard      : C99                                  *
* *
*******************************************************/

#include <stdio.h>
#include <math.h>

// Function Declarations
int SumOfN(int num);
int factorial(int num);
void printupto100(int num);

// ---

// Function Definitions

/**
 * @brief Calculates the sum of the first N natural numbers using recursion.
 * Example: SumOfN(3) = 3 + SumOfN(2) = 3 + (2 + SumOfN(1)) = 3 + 2 + 1 = 6
 * @param num The upper limit (N) for the sum.
 * @return The sum of numbers from 1 to num.
 */
int SumOfN(int num)
{
    // Base condition: If num is 1, the sum is 1. This stops the recursion.
    if (num == 1)
    {
        return 1;
    }
    // Recursive step: sum of num and the sum of numbers up to (num - 1).
    return num + SumOfN(num - 1);
}

/**
 * @brief Calculates the factorial of a number using recursion.
 * Example: factorial(4) = 4 * factorial(3) = 4 * (3 * factorial(2)) = 4 * 3 * (2 * factorial(1)) = 4 * 3 * 2 * 1 = 24
 * @param num The number for which to calculate the factorial.
 * @return The factorial of the number.
 */
int factorial(int num)
{
    // Base condition: The factorial of 1 (or 0) is 1. This stops the recursion.
    if (num == 1 || num == 0) // Factorial of 0 is also 1
    {
        return 1;
    }
    // Recursive step: num multiplied by the factorial of (num - 1).
    return num * factorial(num - 1);
}

/**
 * @brief Prints numbers from a given 'num' down to 1 using recursion.
 * If you want to print from 1 up to 'num', change the position of printf.
 * @param num The starting number for printing.
 */
void printupto100(int num)
{
    // Base condition: If num becomes 0, stop the recursion.
    if (num == 0)
    {
        return;
    }

    // This printf statement will print numbers in decreasing order (e.g., 50, 49, ..., 1)
    printf("%d\n", num);

    // Recursive call to print the next smaller number.
    printupto100(num - 1);

    // If you uncomment the line below and comment the one above, it will print in increasing order (e.g., 1, 2, ..., 50)
    // printf("%d\n", num);
}

// ---

// Main Function
int main(int argc, char *argv[])
{
    int num; // Declare num here to be used for different function calls

    // --- Sum of N Numbers ---
    num = 10; // Set num to 10 for SumOfN example
    int sum = SumOfN(num);
    printf("--- Sum of N Numbers ---\n");
    printf("Sum of numbers from 1 to %d using recursion: %d\n\n", num, sum);

    // --- Factorial Calculation ---
    num = 5; // Set num to 5 for factorial example
    int result = factorial(num);
    printf("--- Factorial Calculation ---\n");
    printf("Factorial of %d using recursion: %d\n\n", num, result);

    // --- Printing Numbers Recursively ---
    num = 50; // Set num to 50 for printupto100 example
    printf("--- Printing Numbers Recursively (from %d down to 1) ---\n", num);
    printupto100(num);
    printf("\n"); // Add a newline for better formatting after printing

    return 0; // Indicate successful execution
}