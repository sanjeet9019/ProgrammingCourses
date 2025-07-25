/*******************************************************
* Author        : Sanjeet Prasad
* Description   : Main driver for modular arithmetic demo
* Date          : 26th June 2025
*******************************************************/
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main(int argc, char *argv[])
{
    int a = 20, b = 5;

    printf("Addition      : %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction   : %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division      : %d / %d = %.2f\n", a, b, divide(a, b));

    return 0;
}
