/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : Stack implementation in C using array
*               Demonstrates push, pop, peek, and display operations
* Date        : 12th July 2025
***********************************************/

#include <stdio.h>
#include "stack.h"

#define SIZE 100
int stack[SIZE];
int top = -1; // Stack starts empty

/**
 * Function    : push
 * Description : Adds a value to the top of the stack.
 *               Handles overflow gracefully with diagnostics.
 */
void push(int value) {
    printf("[Push] Attempting to push %d...\n", value);
    if (top >= SIZE - 1) {
        printf("  → Stack Overflow. Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("  Successfully pushed %d. Top is now at index %d\n", value, top);
    }
}

// Pop: Remove and return the top value from the stack
int pop() {
    printf("Attempting to pop the top element...\n");
    if (top < 0) {
        printf("  Stack Underflow. Stack is empty.\n");
        return -1;
    } else {
        int popped = stack[top--];
        printf("  Successfully popped %d. Top moved to index %d\n", popped, top);
        return popped;
    }
}

// Peek: View the top element without removing it
void peekStack() {
    printf("Checking the top element...\n");
    if (top < 0)
        printf("Stack is empty. No top element.\n");
    else
        printf("Top element is: %d (at index %d)\n", stack[top], top);
}

// Display: Show all elements from top to bottom
void displayStack() {
    printf("Displaying all stack elements from top to bottom...\n");
    if (top < 0)
        printf("Stack is empty. Nothing to display.\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("stack[%d] = %d\n", i, stack[i]);
    }
}

// Demo: Run a sequence of stack operations
void runStackDemo() {
    printf("\n=== Stack Demo Begins ===\n");

    printf("\n[1] Pushing three values: 5, 10, 15\n");
    push(5);
    push(10);
    push(15);

    printf("\n[2] Peeking at the top element\n");
    peekStack();

    printf("\n[3] Displaying current stack contents\n");
    displayStack();

    printf("\n[4] Popping one value from the stack\n");
    pop();

    printf("\n[5] Peeking again after popping\n");
    peekStack();

    printf("\n[6] Final stack contents after all operations\n");
    displayStack();

    printf("\n=== Stack Demo Ends ===\n");
}