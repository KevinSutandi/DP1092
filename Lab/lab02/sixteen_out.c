// Convert a 16-bit signed integer to a string of binary digits
// Made by Kevin Edbert Sutandi (z5352065)
// Date 27 January 2022 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
        printf("%s\n", bits);

        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {
    // For Storing Result Binary
    char *binary = malloc(sizeof(char) * (N_BITS + 1)); 
    
    binary[N_BITS] = '\0';

    for (int counter = 0; counter < N_BITS; counter++) {
        // Make a mask to find which position is set or not
        int mask = 1 << (N_BITS - counter - 1);
        // If both value of input and mask is 1 set array to 1
        if (value & mask) { 
            binary[counter] = '1';
        }
        // If not then it will turn to zero 
        else { 
            binary[counter] = '0';
        }

    }
    return binary;
}

