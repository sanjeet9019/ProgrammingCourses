/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates an alternate C syntax  *
*                 using `<%` and `%>` for block braces*
*                 as defined in ISO C standards.      *
*                 Outputs "Hello, World!" using a     *
*                 minimal program structure.          *
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99 (with digraphs support)         *
*                                                     *
*******************************************************/

#include <stdio.h>

int main() <%
    printf("Hello, World!\n");
    return 0;
%>
