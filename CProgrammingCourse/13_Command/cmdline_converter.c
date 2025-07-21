/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates C command-line argument*
*                 handling using `argc` and `argv`.   *
*                 Also illustrates the use of `atoi()`*
*                 for string-to-integer conversion and*
*                 performs basic arithmetic including *
*                 unit conversion from meters to cm.  *
* Created On    : 19th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    int a = 10;
    int b = 20;

    printf("Sum of two numbers = %d\n", sum(a, b));

    // Display number of command-line arguments
    printf("Total number of command-line arguments (argc) = %d\n", argc);

    // List all command-line arguments
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    // Convert first argument to integer
    if (argc > 1)
    {
        int num1 = atoi(argv[1]); // Convert "10" -> 10
        printf("atoi(argv[1]) = %d (as integer)\n", num1);

        // Convert meters to centimeters
        int cm = num1 * 100;
        printf("Converted value in centimeters: %d cm\n", cm);
    }
    else
    {
        printf("Please provide a numeric value as a command-line argument.\n");
    }

    return 0;
}
