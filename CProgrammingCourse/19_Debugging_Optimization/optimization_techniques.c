/*******************************************************
* Author        : Sanjeet Prasad
* Email         : sanjeet8.23@gmail.com
* Description   : Demonstrates C optimization techniques
* Date          : 10th July 2025
*******************************************************/

#include <stdio.h>

// ⚙️ 1. Better Design Algorithm
// Instead of storing result in a variable, directly return the expression
int sum_optimized(int a, int b) {
    return a + b; // More efficient than using intermediate variables
}

// 🧠 2. Appropriate Datatype
// Using unsigned char for small positive values conserves memory
void datatype_demo() {
    unsigned char marks = 95; // Ideal for values between 0-255
    char age = 100; // 1-byte variable for small range
    printf("Marks = %u, Age = %d\n", marks, age);
}

// 🔁 3. Optimize Loop
void optimized_loop(int a, int b, int c) {
	int d = 10;
    int result = a + b + c * d; // Pre-calculate outside loop
    for (int i = 0; i < 3; i++) {
        int temp = result * i; // Avoid recalculating inside loop
        printf("Loop %d: %d\n", i, temp);
    }
}

// 📌 4. const and static usage
const float PI = 3.14; // Value won't change, makes code safer and compiler can optimize
static int counter = 0; // Preserves value across function calls

void static_demo() {
    counter++;
    printf("Static counter = %d\n", counter);
}

// ➕ 5. Inline Function (available in some compilers)
static inline int add_inline(int a, int b) {
    return a + b;
}

// 🔢 6. Bitwise Operations for Powers of 2
void bitwise_demo() {
    int num = 2;
    int shifted_left = num << 1; // 2 * 2 = 4
    int shifted_right = num >> 1; // 2 / 2 = 1
    printf("Bitwise Left: %d, Right: %d\n", shifted_left, shifted_right);
}

// ⚡ 7. register Keyword (Hint to store variable in CPU register)
void register_demo() {
    register int fastCounter;
    for (fastCounter = 0; fastCounter < 3; fastCounter++) {
        printf("register loop: %d\n", fastCounter);
    }
}

// 🔧 8. Compiler Optimization Flags
// Note: These are not part of the C source code but passed at compilation:
// gcc -O1 filename.c      -> Basic optimization
// gcc -O2 filename.c      -> More aggressive
// gcc -O3 filename.c      -> Maximum optimization (may increase compile time)

int main() {
    printf("1. Better Algorithm Design:\n");
    printf("Sum = %d\n", sum_optimized(10, 20));

    printf("\n2. Appropriate Datatypes:\n");
    datatype_demo();

    printf("\n3. Optimized Loop:\n");
    optimized_loop(10, 20, 5);

    printf("\n4. Const and Static:\n");
    static_demo(); static_demo(); static_demo(); // Shows persistent static value

    printf("\n5. Inline Function:\n");
    printf("Inline Add = %d\n", add_inline(5, 7));

    printf("\n6. Bitwise Operations:\n");
    bitwise_demo();

    printf("\n7. Register Keyword:\n");
    register_demo();

    printf("\n8. Compiler Flags:\n");
    printf("Use -O1, -O2, -O3 with gcc for different levels of optimization.\n");

    return 0;
}
