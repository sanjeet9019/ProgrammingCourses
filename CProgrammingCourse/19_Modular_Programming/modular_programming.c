/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates modular programming in *
*                 C by separating logic into discrete *
*                 functions—`increment()` and         *
*                 `decrement()`—that operate on a     *
*                 passed integer value. Illustrates   *
*                 how modularity improves clarity,    *
*                 reusability, and maintainability.   *
* Created On    : 26th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Increments the given integer and prints the result.
 * @param a Integer value to be incremented.
 */
void increment(int a)
{
    a = a + 1;
    printf("Increment of a number = %d\n", a);
}

/**
 * @brief Decrements the given integer and prints the result.
 * @param a Integer value to be decremented.
 */
void decrement(int a)
{
    a = a - 1;
    printf("Decrement of a number = %d\n", a);
}

/**
 * @brief Entry point of the program. Tests increment and decrement.
 */
int main(int argc, char *argv[])
{
    increment(5);
    decrement(10);
    return 0;
}
