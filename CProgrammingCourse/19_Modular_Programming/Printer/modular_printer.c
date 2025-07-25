/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Defines the function `printextern()`*
*                 which accesses and prints the value *
*                 of an external global variable `extnum`,*
*                 declared via `extern` in a header.  *
*                 Demonstrates use of extern linkage  *
*                 across C modules.                   *
* Created On    : 26th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/

#include <stdio.h>
#include "modular_header.h"

/**
 * @brief Prints the value of the external variable `extnum`.
 * This function relies on `extnum` being defined in another file
 * and declared with `extern` in the modular_header.h file.
 */
void printextern()
{
    printf("extern variable value = %d\n", extnum);
}
