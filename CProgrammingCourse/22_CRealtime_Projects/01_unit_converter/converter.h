/*
 * converter.h - Header file for the converter library.
 *
 * This header defines the interface for a set of utility functions designed
 * for both number base conversions (binary, octal, decimal, hexadecimal)
 * and common unit conversions (length, weight, temperature). It also includes
 * declarations for input validation routines to ensure correct data handling.
 */
#ifndef CONVERTER_H
#define CONVERTER_H

// Base conversion functions
int binary_to_decimal(const char *binary);
int octal_to_decimal(const char *octal);
int hex_to_decimal(const char *hex);
void decimal_to_binary(int decimal, char *output);
void decimal_to_octal(int decimal, char *output);
void decimal_to_hex(int decimal, char *output);

// Unit conversion functions
float convert_length(float value, const char *from_unit, const char *to_unit);
float convert_weight(float value, const char *from_unit, const char *to_unit);
float convert_temperature(float value, const char *from_unit, const char *to_unit);

// Validation functions
int is_valid_base_input(const char *input, const char *base);
int is_valid_unit(const char *unit, const char *category);

#endif // CONVERTER_H