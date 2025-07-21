/*******************************************************
*                                                     *
* Author       : Sanjeet Prasad                       *
* Email        : sanjeet8.23@gmail.com                *
* Description  : Demonstrates C operators              *
*                including arithmetic, relational,     *
*                logical, bitwise, ternary,            *
*                and expression evaluation examples    *
* Created On   : 2nd May 2025                         *
* Compiler     : GCC 14.2.0                           *
* Standard     : C99                                  *
*                                                     *
*******************************************************/

#include <stdio.h>
#include <stdbool.h>

#define READ    100
#define WRITE   010
#define EXEC    001

int main() {
    int a = 10, b = 3, result;

    // Arithmetic Operators
    printf("Arithmetic Operations:\n");
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %d\n", a / b);
    printf("Modulus: %d\n\n", a % b);

    // Relational Operators
    printf("Relational Operations:\n");
	bool result1 ;
	result = (a == b);
    printf("a == b: %d\n",result1);
    printf("a != b: %d\n", a != b);
    printf("a > b: %d\n", a > b);
    printf("a < b: %d\n\n", a < b);

    a = 10, b = 3, result;
    // Logical Operators
    printf("Logical Operations:\n");
    printf("(a > 0 && b < 5): %d\n", (a > 0 && b < 5));
    printf("(a > 0 || b > 5): %d\n", (a > 0 || b > 5));
    printf("!(a == b): %d\n\n", !(a == b));

    // Bitwise Operators
	a = 10, b = 3;
    printf("Bitwise Operations:\n");
    printf("Bitwise AND: %d\n", a & b);
    printf("Bitwise OR: %d\n", a | b);
    printf("Bitwise XOR: %d\n", a ^ b);
    printf("Left Shift (a << 1): %d\n", a << 1);
    printf("Right Shift (a >> 1): %d\n\n", a >> 1);

    // Assignment Operators
    printf("Assignment Operations:\n");
    result = a;  // Assigning value
    result += 5; // result = result + 5
    printf("result += 5: %d\n", result);
    
    result *= 2; // result = result * 2
    printf("result *= 2: %d\n", result);
    
    result /= 3; // result = result / 3
    printf("result /= 3: %d\n", result);
    
    result %= 4; // result = result % 4
    printf("result %%= 4: %d\n", result);
	
	int x = 5;

    printf("Post-Increment: %d\n", x++); // Uses x, then increases
    printf("After Post-Increment: %d\n", x);

    printf("Pre-Decrement: %d\n", --x); // Decreases x, then uses
	
	int num = 7;
    bool result2 = (num % 2 == 0) ? true : false;

    printf("The ternary is: %d\n", result2);
	
	num = 42;  // Example number (Binary: 101010)
    int k = 3;  // Target bit position

    // Check if num is a power of two
    if ((num > 0) && ((num & (num - 1)) == 0)) {
        printf("%d is a power of two.\n", num);
    } else {
        printf("%d is NOT a power of two.\n", num);
    }

    // Set k-th bit
    int set_bit_result = num | (1 << k);
    printf("Setting bit %d in %d gives: %d\n", k, num, set_bit_result);

    // Unset k-th bit
    int unset_bit_result = num & ~(1 << k);
    printf("Unsetting bit %d in %d gives: %d\n", k, num, unset_bit_result);

    // Toggle k-th bit
    int toggle_bit_result = num ^ (1 << k);
    printf("Toggling bit %d in %d gives: %d\n", k, num, toggle_bit_result);

    // Check if num is odd
    if (num & 1) {
        printf("%d is an odd number.\n", num);
    } else {
        printf("%d is an even number.\n", num);
    }

    result = 8 + 2 / 2 * 3 - 1;  // Unexpected behavior?
	
	result = 8 + 2 * 2 / 3 - 1;  // Unexpected behavior?
	
	result = 10 - 5 * 2;  // Common mistake?
	
    printf("Result: %d\n", result);  // What would this print?
	
	float original_price = 1000.0;
    float discount = 20.0;  // 20% discount
    float final_price;

    final_price = original_price - discount * original_price / 100;  // Incorrect precedence

    printf("Final Price: %.2f\n", final_price);  // Unexpected output
	

	int fileper = READ | WRITE | EXEC;
	
    int original = 42;  
    int key = 123;      

    int encrypted = original ^ key;  
    printf("Encrypted value: %d\n", encrypted);

    int decrypted = encrypted ^ key;  
    printf("Decrypted value: %d\n", decrypted);

    return 0;
}