/*******************************************************
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Implementation file for static demo.*
*                 Contains a static function `helper()`*
*                 and a static variable `counter` that *
*                 retains its value across calls.      *
* Created On    : 26th June 2025                      *
*******************************************************/

#include <stdio.h>
#include "logic_module.h"

// Static helper function: internal to this file only
static int helper(int value)
{
    return value * value;
}

// Static variable retains value across multiple function calls
void expose_static_logic(int input)
{
    static int counter = 0;  // Preserved between calls
    counter++;

    int squared = helper(input);
    printf("Call #%d | Input: %d | Squared: %d | Counter: %d\n",
           counter, input, squared, counter);
}
