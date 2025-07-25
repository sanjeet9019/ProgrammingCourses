/*******************************************************
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Entry point for static keyword demo.*
*                 Calls external function that uses a *
*                 static helper and static counter.   *
* Created On    : 26th June 2025                      *
*******************************************************/

#include <stdio.h>
#include "logic_module.h"

int main(int argc, char *argv[])
{
    // Call function multiple times to observe static behavior
    for (int i = 0; i < 3; i++) {
        expose_static_logic(i + 1);
    }

    return 0;
}

