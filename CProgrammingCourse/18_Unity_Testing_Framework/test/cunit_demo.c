/*******************************************************
 * Author        : Sanjeet Prasad
 * Email         : sanjeet8.23@gmail.com
 * Description   : Demonstrates modular unit testing in C 
 *                 using the Unity framework. Each logical 
 *                 assertion is split into a separate test 
 *                 function for granular pass/fail analysis.
 * Created On    : 14th July 2025
 *******************************************************/

#include <stdio.h>
#include <string.h>
#include "unity.h"
#include "math_util.h"   // Math function declarations

int a, b;

void setUp(void)
{
    a = 20;
    b = 5;
    printf("setUp : a = %d, b = %d\n", a, b);
}

void tearDown(void)
{
    printf("tearDown : a = %d, b = %d\n", a, b);
    a = 0;
    b = 0;
}

// 🌟 ADDITION TESTS
void test_add_returns_25(void)                         { TEST_ASSERT_EQUAL_INT(25, add(a, b)); }
void test_add_is_greater_than_inputs(void)             { TEST_ASSERT_TRUE(add(a, b) > a && add(a, b) > b); }
void test_add_intentional_fail_20(void)                { TEST_ASSERT_EQUAL_INT_MESSAGE(20, add(a, b), "Intentional fail: add(20,5) != 20"); }

// 🌟 SUBTRACTION TESTS
void test_sub_returns_15(void)                         { TEST_ASSERT_EQUAL_INT(15, sub(a, b)); }
void test_sub_non_negative(void)                       { TEST_ASSERT_FALSE(sub(a, b) < 0); }
void test_sub_intentional_fail_10(void)                { TEST_ASSERT_EQUAL_INT_MESSAGE(10, sub(a, b), "Intentional fail: sub(20,5) != 10"); }

// 🌟 MULTIPLICATION TESTS
void test_mul_returns_100(void)                        { TEST_ASSERT_EQUAL_INT(100, mul(a, b)); }
void test_mul_even(void)                               { TEST_ASSERT_TRUE(mul(a, b) % 2 == 0); }
void test_mul_intentional_fail(void)                   { TEST_ASSERT_NOT_EQUAL_MESSAGE(100, mul(a, b), "Intentional fail: should actually be equal"); }

// 🌟 DIVISION TESTS
void test_div_returns_4(void)                          { TEST_ASSERT_EQUAL_INT(4, div(a, b)); }
void test_div_less_than_a(void)                        { TEST_ASSERT_TRUE(div(a, b) < a); }
void test_div_intentional_fail_5(void)                 { TEST_ASSERT_EQUAL_INT_MESSAGE(5, div(a, b), "Intentional fail: div(20,5) != 5"); }
void test_div_intentional_fail_3(void)                 { TEST_ASSERT_EQUAL_INT_MESSAGE(4, div(a, b), "Intentional fail: div(20,5) != 3"); }

// 🌟 ADVANCED UTILS (square, max, factorial)
void test_square_should_be_400(void)                   { TEST_ASSERT_EQUAL_INT(400, square(a)); }
void test_max_should_return_a(void)                    { TEST_ASSERT_EQUAL_INT(a, max(a, b)); }
void test_factorial_of_5(void)                         { TEST_ASSERT_EQUAL_INT(120, factorial(5)); }
void test_factorial_negative_should_be_invalid(void)   { TEST_ASSERT_EQUAL_INT(-1, factorial(-5)); }
void test_factorial_greater_than_1000(void)            { TEST_ASSERT_GREATER_THAN(1000, factorial(7)); }

// 🌟 BITWISE LOGIC ASSERTIONS
void test_bits_should_be_equal(void)
{
    unsigned char val1 = 0xF0;
    unsigned char val2 = 0xF0;
    TEST_ASSERT_BITS(0xFF, val1, val2);
}

void test_bits_high_on_mask(void)
{
    unsigned char result = 0xFF;
    TEST_ASSERT_BITS_HIGH(0x0F, result); // check lower nibble is high
}

void test_bits_low_on_mask(void)
{
    unsigned char result = 0x00;
    TEST_ASSERT_BITS_LOW(0x0F, result); // check lower nibble is low
}

// 🌟 STRING CHECKS
void test_string_equality(void)
{
    const char* s1 = "CProgramming";
    const char* s2 = "CProgramming";
    TEST_ASSERT_EQUAL_STRING(s1, s2);
}

void test_string_not_empty(void)
{
    const char* str = "Course";
    TEST_ASSERT_NOT_EMPTY(str);
    TEST_ASSERT_FALSE(strlen(str) == 0);
}

void test_string_empty_check(void)
{
    const char* str = "";
    TEST_ASSERT_EMPTY(str);
    TEST_ASSERT_TRUE(strlen(str) == 0);
}

// 🌟 REAL-WORLD MACRO USAGE

void test_equal_uint(void)                  { TEST_ASSERT_EQUAL_UINT(25u, (unsigned int)add(a, b)); }
void test_equal_hex8(void)                  { TEST_ASSERT_EQUAL_HEX8(0xF0, (unsigned char)mul(16, b)); }

void test_memory_compare(void)
{
    char src[4] = {'a', 'b', 'c', 'd'};
    char dst[4];
    memcpy(dst, src, 4);
    TEST_ASSERT_EQUAL_MEMORY(src, dst, 4);
}

void test_int_array_comparison(void)
{
    int actual[3] = {1, 2, 3};
    int expected[3] = {1, 2, 3};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 3);
}

void test_less_than_logic(void)             { TEST_ASSERT_LESS_THAN(130, mul(a, b)); }
void test_greater_than_logic(void)          { TEST_ASSERT_GREATER_THAN(10, sub(a, b)); }

void test_ignore_case(void)                 { TEST_IGNORE_MESSAGE("Skipped due to hardware dependency"); }
void test_force_fail(void)                  { TEST_FAIL_MESSAGE("Expected failure for logic placeholder"); }

void test_debug_log(void)
{
    TEST_MESSAGE("Running diagnostic for edge-case division...");
    TEST_ASSERT_EQUAL_INT(4, div(20, 5));
}

int main(void)
{
    UNITY_BEGIN();

    // Arithmetic
    RUN_TEST(test_add_returns_25);
    RUN_TEST(test_add_is_greater_than_inputs);
    RUN_TEST(test_add_intentional_fail_20);
    RUN_TEST(test_sub_returns_15);
    RUN_TEST(test_sub_non_negative);
    RUN_TEST(test_sub_intentional_fail_10);
    RUN_TEST(test_mul_returns_100);
    RUN_TEST(test_mul_even);
    RUN_TEST(test_mul_intentional_fail);
    RUN_TEST(test_div_returns_4);
    RUN_TEST(test_div_less_than_a);
    RUN_TEST(test_div_intentional_fail_5);
    RUN_TEST(test_div_intentional_fail_3);

    // Advanced Math
    RUN_TEST(test_square_should_be_400);
    RUN_TEST(test_max_should_return_a);
    RUN_TEST(test_factorial_of_5);
    RUN_TEST(test_factorial_negative_should_be_invalid);
    RUN_TEST(test_factorial_greater_than_1000);

    // Bitwise
    RUN_TEST(test_bits_should_be_equal);
    RUN_TEST(test_bits_high_on_mask);
    RUN_TEST(test_bits_low_on_mask);

    // String Handling
    RUN_TEST(test_string_equality);
    RUN_TEST(test_string_not_empty);
    RUN_TEST(test_string_empty_check);

    // Real-World Utility
    RUN_TEST(test_equal_uint);
    RUN_TEST(test_equal_hex8);
    RUN_TEST(test_memory_compare);
    RUN_TEST(test_int_array_comparison);
    RUN_TEST(test_less_than_logic);
    RUN_TEST(test_greater_than_logic);
    RUN_TEST(test_ignore_case);
    RUN_TEST(test_force_fail);
    RUN_TEST(test_debug_log);

    return UNITY_END();
}