/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates various uses of        *
*                 function pointers in C, including   *
*                 callbacks, pointers with structs,   *
*                 dynamic memory, and typedef aliases.*
*                 Covers real-world examples like     *
*                 printer device simulation, arithmetic*
*                 operations, and struct-based logic. *
* Created On    : 25th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "callback_funcptr.h"

// Printer device functions
void printerstart() {
    printf("Printer start\n");
}

void printerstop() {
    printf("Printer stop\n");
}

// Arithmetic functions
int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

// Callback function using typedef FUNPTR
void MathOperation(FUNPTR funptr, int num1, int num2, const char *operations) {
    int result = funptr(num1, num2);
    printf("MathOperation operations = %s, Result = %d\n", operations, result);
}

// Greeting function
void greet(void) {
    printf("Hello to Sneha\n");
}

// Return pointer from function
int *returnintptr(int a) {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Malloc failed\n");
        return NULL;
    }
    *ptr = a * 10;
    return ptr;
}

// Struct-related functions
void structfunc(POINT p) {
    printf("Struct Point P values: x = %d, y = %d\n", p.x, p.y);
}

POINT structfuncret(POINT p) {
    POINT p1 = { .x = p.x * 99, .y = p.y * 99 };
    return p1;
}

int main(int argc, char *argv[]) {
    greet();

    // Version 1: void function pointer
    void (*fptrgreet)();
    fptrgreet = greet;
    printf("Address of greet function = 0x%p\n", greet);
    fptrgreet();

    // Version 2: Arithmetic function pointers
    int (*funptrsum)(int, int) = sum;
    printf("Address of sum() = 0x%p\n", sum);
    printf("Sum using pointer = %d\n", funptrsum(200, 300));

    // Version 3: Pointer-returning function
    int* (*funretptr)(int) = returnintptr;
    int *iptr = funretptr(10);
    if (iptr != NULL) {
        printf("Returned pointer value = %d\n", *iptr);
        free(iptr);
        iptr = NULL;
    }

    // Version 4: Struct function pointer
    void (*structptr)(POINT) = structfunc;
    POINT p = { .x = 100, .y = 200 };
    printf("Using struct pointer as parameter:\n");
    structptr(p);

    // Version 5: Struct return function pointer
    POINT (*structptr1)(POINT) = structfuncret;
    POINT retvalue = structptr1(p);
    printf("Returned Point: x = %d, y = %d\n", retvalue.x, retvalue.y);

    // Callback arithmetic
    MathOperation(sum, 10, 10, "Sum");
    MathOperation(sub, 10, 5, "Subtraction");
    MathOperation(mul, 10, 2, "Multiplication");
    MathOperation(divide, 20, 4, "Division");

    // Struct with function pointers
    DEVICE printer = {
        .start = printerstart,
        .stop = printerstop,
        .name = "HP Printer",
        .status = 0
    };

    printf("Printer Name = %s\n", printer.name);
    printer.start();
    printer.status = 1;
    printer.stop();

    return 0;
}


