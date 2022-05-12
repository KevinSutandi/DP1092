// Multiply a float by 2048 using bit operations only
// Made by : Kevin Edbert Sutandi
// Date: somethin January 2022

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// float_2048 is given the bits of a float f as a uint32_t
// it uses bit operations and + to calculate f * 2048
// and returns the bits of this value as a uint32_t
//
// if the result is too large to be represented as a float +inf or -inf is returned
//
// if f is +0, -0, +inf or -inf, or Nan it is returned unchanged
//
// float_2048 assumes f is not a denormal number
//
uint32_t float_2048(uint32_t f) {
    // Reusing float_components_t from float_bits.c
    float_components_t value;
    int sign_mask = 1;
    int expo_mask = 0xFF;
    int frac_mask = 0x7FFFFF;
    value.sign = (f >> 31) & sign_mask;
    value.exponent = (f >> 23) & expo_mask;
    value.fraction = f & frac_mask;

    // Only run if statement if exponent is not 0 or 0xFF 
    if (value.exponent != 0 && value.exponent != 0xFF) {
        // If exponent is not 0 or 0xFF, then multiply by 2048
        // adding = 0x0b is equivalent to multiplying by 2048
        value.exponent = value.exponent + 0x0b;
        // If exponent is equal or gereater than 0xFF
        // change value to infinity which is 0xFF for exponent
        // and 0 for fraction
        if (value.exponent >= 0xFF) {
            value.exponent = 0xFF;
            value.fraction = 0;
        }
    }
    // Return sign, exponent and fraction combined
    return (value.sign << 31) | (value.exponent << 23) | value.fraction;

}

