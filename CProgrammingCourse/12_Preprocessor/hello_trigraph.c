/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates the use of trigraphs   *
*                 in C programming as a substitute    *
*                 for special characters like `{}`,   *
*                 and `#`. This minimal program uses  *
*                 `??=` for `#`, `??<` for `{`, and   *
*                 `??>` for `}` to print "Hello, World!".
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99 or earlier (trigraph support)   *
*                                                     *
*******************************************************/
??=include <stdio.h>

int main() ??< 
    printf("Hello, World!\n");
    return 0;
??>
