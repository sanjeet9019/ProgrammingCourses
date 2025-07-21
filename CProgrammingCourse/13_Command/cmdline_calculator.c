/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Command-line calculator in C that   *
*                 accepts two integer operands and    *
*                 a basic arithmetic operator (+, -,  *
*                 *, /) from user input. Demonstrates *
*                 `argc`, `argv`, and `atoi()` usage  *
*                 for argument parsing and conversion.*
* Created On    : 19th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Command-line calculator that performs basic arithmetic.
 * Usage: ./cmdline_calculator <num1> <op> <num2>
 * Example: ./cmdline_calculator 10 + 20
 */

int main(int argc, char *argv[])
{
    printf("Total number of command line arguments (argc) = %d\n", argc);

    // Expect exactly 4 arguments: program name, num1, operator, num2
    if (argc != 4)
    {
        printf("Incorrect usage!\n");
        printf("Format: ./program_name <num1> <operator> <num2>\n");
        return -1;
    }

    // Display command-line arguments
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // Extract values
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char op = argv[2][0];
    int result = 0;

    // Perform calculation based on operator
    switch (op)
    {
        case '+':
            result = num1 + num2;
            printf("Sum result = %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Subtraction result = %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Multiplication result = %d\n", result);
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("Division result = %d\n", result);
            }
            break;
        default:
            printf("Unsupported operator: %c\n", op);
    }

    return 0;
}
