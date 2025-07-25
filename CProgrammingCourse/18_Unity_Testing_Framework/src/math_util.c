#include "math_util.h"
int x = 100;
// Basic Arithmetic Operations
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b; // no division-by-zero check for simplicity
}

// Additional Math Utilities
int square(int x) {
    return x * x;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int factorial(int n) {
    if (n < 0) return -1;
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}