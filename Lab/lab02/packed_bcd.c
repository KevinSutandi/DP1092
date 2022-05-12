// Convert an 8 digit Packed BCD Value to an Integer
// Made by Kevin Edbert Sutandi (z5352065)
// Date 30 January 2022

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BCD_DIGITS 8

uint32_t packed_bcd(uint32_t packed_bcd);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= UINT32_MAX);
        uint32_t packed_bcd_value = l;

        printf("%lu\n", (unsigned long)packed_bcd(packed_bcd_value));
    }

    return 0;
}

// given a packed BCD encoded value between 0 .. 99999999
// return the corresponding integer
uint32_t packed_bcd(uint32_t packed_bcd_value) {
    // Mask is 0xF because divide by 4    
    int mask = 0xF;
    int value = 0;
    // Loop Counter Decrementing as unable to use <math.h> for 10^counter
    for (int counter = 7; counter >= 0; counter--) {
        int digit_rest = (packed_bcd_value >> (counter * 4)) & mask;
        value = digit_rest + (value * 10);
    }
    return value;
}
