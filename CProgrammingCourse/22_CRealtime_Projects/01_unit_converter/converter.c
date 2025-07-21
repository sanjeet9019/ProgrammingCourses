/*
 * converter.c - A comprehensive library for number base and unit conversions.
 *
 * This file provides functions for converting between different number bases
 * (binary, octal, decimal, hexadecimal) and for converting various units of
 * measurement, including length, weight, and temperature. It also includes
 * basic input validation functions to ensure data integrity.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "converter.h"

// Base conversions
int binary_to_decimal(const char *binary) {
    int result = 0;
    while (*binary) {
        result = result * 2 + (*binary++ - '0');
    }
    return result;
}

int octal_to_decimal(const char *octal) {
    return (int)strtol(octal, NULL, 8);
}

int hex_to_decimal(const char *hex) {
    return (int)strtol(hex, NULL, 16);
}

void decimal_to_binary(int decimal, char *output) {
    itoa(decimal, output, 2);
}

void decimal_to_octal(int decimal, char *output) {
    itoa(decimal, output, 8);
}

void decimal_to_hex(int decimal, char *output) {
    itoa(decimal, output, 16);
}

// Unit conversion helpers
float convert_length(float value, const char *from, const char *to) {
    const char *units[] = {"m", "cm", "mm"};
    const float scales[] = {1.0, 0.01, 0.001};  // Convert to meters

    int i = -1, j = -1;
    for (int k = 0; k < 3; k++) {
        if (strcmp(from, units[k]) == 0) i = k;
        if (strcmp(to, units[k]) == 0) j = k;
    }

    if (i != -1 && j != -1) {
        float value_in_meters = value * scales[i];
        return value_in_meters / scales[j];
    }
    return -1.0;
}

float convert_weight(float value, const char *from, const char *to) {
    const char *units[] = {"kg", "g", "mg"};
    const float scales[] = {1.0, 0.001, 0.000001};  // Convert to kilograms

    int i = -1, j = -1;
    for (int k = 0; k < 3; k++) {
        if (strcmp(from, units[k]) == 0) i = k;
        if (strcmp(to, units[k]) == 0) j = k;
    }

    if (i != -1 && j != -1) {
        float value_in_kg = value * scales[i];
        return value_in_kg / scales[j];
    }
    return -1.0;
}

float convert_temperature(float value, const char *from, const char *to) {
    if (strcmp(from, "C") == 0 && strcmp(to, "F") == 0)
        return value * 9.0 / 5.0 + 32.0;
    else if (strcmp(from, "F") == 0 && strcmp(to, "C") == 0)
        return (value - 32.0) * 5.0 / 9.0;
    else if (strcmp(from, "C") == 0 && strcmp(to, "K") == 0)
        return value + 273.15;
    else if (strcmp(from, "K") == 0 && strcmp(to, "C") == 0)
        return value - 273.15;
    return -1.0;
}

// Simple input validation
int is_valid_base_input(const char *input, const char *base) {
    while (*input) {
        char ch = toupper(*input++);
        if (strcmp(base, "binary") == 0 && (ch != '0' && ch != '1')) return 0;
        if (strcmp(base, "octal") == 0 && (ch < '0' || ch > '7')) return 0;
        if (strcmp(base, "hex") == 0 && !isxdigit(ch)) return 0;
    }
    return 1;
}

int is_valid_unit(const char *unit, const char *category) {
    if (strcmp(category, "length") == 0)
        return strcmp(unit, "m") == 0 || strcmp(unit, "cm") == 0 || strcmp(unit, "mm") == 0;
    if (strcmp(category, "weight") == 0)
        return strcmp(unit, "kg") == 0 || strcmp(unit, "g") == 0 || strcmp(unit, "mg") == 0;
    if (strcmp(category, "temperature") == 0)
        return strcmp(unit, "C") == 0 || strcmp(unit, "F") == 0 || strcmp(unit, "K") == 0;
    return 0;
}