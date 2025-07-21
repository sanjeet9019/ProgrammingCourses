/*
 * main.c - Test suite for the converter library.
 *
 * This program demonstrates the usage of functions provided by the "converter.h" library.
 * It includes a series of tests for number base conversions (binary, octal, hex to decimal,
 * and decimal to binary, octal, hex) as well as unit conversions for length, weight,
 * and temperature. Additionally, it verifies the input validation functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "converter.h"

int main() {
	system("chcp 65001");  // Set code page to UTF-8
    // 1️⃣ Test Base Conversion (Binary, Octal, Hex → Decimal)
    printf("[Base Conversion]\n");
    printf("Binary '1010' to Decimal: %d\n", binary_to_decimal("1010"));        // Expected: 10
    printf("Octal '17' to Decimal: %d\n", octal_to_decimal("17"));              // Expected: 15
    printf("Hex '1F' to Decimal: %d\n", hex_to_decimal("1F"));                  // Expected: 31

    // 2️⃣ Test Decimal to Binary, Octal, Hex
    char output[32];
    decimal_to_binary(42, output);
    printf("Decimal 42 to Binary: %s\n", output);                               // Expected: 101010

    decimal_to_octal(42, output);
    printf("Decimal 42 to Octal: %s\n", output);                                // Expected: 52

    decimal_to_hex(42, output);
    printf("Decimal 42 to Hex: %s\n", output);                                  // Expected: 2A

    // 3️⃣ Test Unit Conversion: Length
    printf("\n[Unit Conversion – Length]\n");
    printf("1.5m to cm: %.2f\n", convert_length(1.5, "m", "cm"));               // Expected: 150.00
    printf("2500mm to m: %.4f\n", convert_length(2500, "mm", "m"));            // Expected: 2.5000

    // 4️⃣ Test Unit Conversion: Weight
    printf("\n[Unit Conversion – Weight]\n");
    printf("2kg to g: %.2f\n", convert_weight(2, "kg", "g"));                  // Expected: 2000.00
    printf("750000mg to kg: %.6f\n", convert_weight(750000, "mg", "kg"));      // Expected: 0.750000

    // 5️⃣ Test Unit Conversion: Temperature
    printf("\n[Unit Conversion – Temperature]\n");
    printf("25°C to °F: %.2f\n", convert_temperature(25, "C", "F"));            // Expected: 77.00
    printf("98.6°F to °C: %.2f\n", convert_temperature(98.6, "F", "C"));        // Expected: 37.00
    printf("0°C to K: %.2f\n", convert_temperature(0, "C", "K"));               // Expected: 273.15

    // 6️⃣ Test Validation: Base Input
    printf("\n[Validation – Base Input]\n");
    printf("Is '1101' valid binary? %s\n", is_valid_base_input("1101", "binary") ? "Yes" : "No");
    printf("Is '78' valid octal? %s\n", is_valid_base_input("78", "octal") ? "Yes" : "No");
    printf("Is '1F3G' valid hex? %s\n", is_valid_base_input("1F3G", "hex") ? "Yes" : "No");  // G is invalid

    // 7️⃣ Test Validation: Unit Input
    printf("\n[Validation – Units]\n");
    printf("Is 'cm' a valid length unit? %s\n", is_valid_unit("cm", "length") ? "Yes" : "No");
    printf("Is 'ton' a valid weight unit? %s\n", is_valid_unit("ton", "weight") ? "Yes" : "No");
    printf("Is 'F' a valid temperature unit? %s\n", is_valid_unit("F", "temperature") ? "Yes" : "No");

    return 0;
}