// Convert a 2 digit BCD Value to an Integer
// Made by Kevin Edbert Sutandi (z5352065)
// Date 30 January 2022

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int bcd(int bcd_value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= 0x0909);
        int bcd_value = l;

        printf("%d\n", bcd(bcd_value));
    }

    return 0;
}

// given a  BCD encoded value between 0 .. 99
// return corresponding integer
// Understanding :
// Using Binary 2's Complement
// Split binary to 2 and determine the decimal
int bcd(int bcd_value) {
    int mask_1 = 0x00FF;
    int mask_2 = 0xFF00;
    int split_1 = bcd_value & mask_1;
    int split_2 = ((bcd_value & mask_2) / 256)*10;

    return split_1 + split_2;
}

