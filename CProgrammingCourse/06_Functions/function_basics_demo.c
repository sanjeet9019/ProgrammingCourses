/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates basic C functions        *
*                including declaration, definition,    *
*                calling, and math.h usage             *
* Created On   : 21st May 2025                        *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <math.h>

#define PI 3.14

// 🧮 Enum example (for reference)
enum result { TRUE, FALSE };

// 🔧 Function declarations
void printgreet(void);                     // Greets user
void sumoftwonumbers(int num1, int num2);  // Prints sum of two numbers
int sumofNatural(int num);                 // Returns sum of 1 to num

// 🔧 Function definitions

// Prints a friendly greeting
void printgreet(void)
{
    printf("Hello World\n");
}

// Prints the sum of two integers
void sumoftwonumbers(int num1, int num2)
{
    int result = num1 + num2;
    printf("Sum of %d and %d = %d\n", num1, num2, result);
}

// Returns sum of first n natural numbers
int sumofNatural(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
        sum += i;
    return sum;
}

// 🧪 Main driver function
int main(int argc, char *argv[])
{
    // Greeting examples
    printgreet();
    printgreet();

    // Sum of two user-defined values
    int num1 = 10, num2 = 20;
    sumoftwonumbers(num1, num2);

    // Sum of natural numbers
    int sumN = sumofNatural(5);
    printf("Sum of first 5 natural numbers = %d\n", sumN);

    // Math library usage
    double number = 16;
    double sqnum = sqrt(number);  // Square root
    printf("Square root of %.2f = %.2f\n", number, sqnum);

    double powerResult = pow(2, 3);  // Exponentiation
    printf("2 raised to power 3 = %.2f\n", powerResult);

    return 0;
}