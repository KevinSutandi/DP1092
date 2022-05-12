// Extract the 3 parts of a float using bit operations only
// Made by Kevin Edbert Sutandi (z5352065)
// Date 31 January 2022

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// separate out the 3 components of a float
// Example : 01000000001000000000000000000000
// Turns into 0 10000000 01000000000000000000000
// fraction = 23 digits
// exponent = 8 digits
// Pos or Neg = 1 digit
float_components_t float_bits(uint32_t f) {
    float_components_t value;
    // Creating masks for each types
    int sign_mask = 1;
    int expo_mask = 0xFF;
    int frac_mask = 0x7FFFFF;
    // Shifting and using bit operations
    value.sign = (f >> 31) & sign_mask;
    value.exponent = (f >> 23) & expo_mask;
    value.fraction = f & frac_mask;
    return value;
}

// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
// NaN is defined as an infinite number 
// with a fractional part
// a.k.a exp = 0xff and frac != 0
int is_nan(float_components_t f) {
    if (f.exponent == 0xFF && f.fraction > 0) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
// It is positive inf if:
// sign is 0x0 | exp = 0xFF | frac = 0x000000
int is_positive_infinity(float_components_t f) {
    if (f.sign == 0x0 && f.exponent == 0xFF && f.fraction == 0x0000000) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
// It is negative inf if:
// sign is 0x1 | exp = 0xFF | frac = 0x000000
int is_negative_infinity(float_components_t f) {
    if (f.sign == 0x1 && f.exponent == 0xFF && f.fraction == 0x0000000) {
        return 1;
    } else {
        return 0;
    }
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
// If it is zero:
// Sign can be 0x0 or 0x1 | exp = 0x00 | frac = 0x000000
int is_zero(float_components_t f) {
    if (f.exponent == 0x00 && f.fraction == 0x0000000) {
        return 1;
    } else {
        return 0;
    }
}
