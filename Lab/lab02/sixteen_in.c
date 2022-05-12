// Convert string of binary digits to 16-bit signed integer
// Made by Kevin Edbert Sutandi (z5352065)
// Date 26 January 2022

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define N_BITS 16

int16_t sixteen_in(char *bits);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        printf("%d\n", sixteen_in(argv[arg]));
    }

    return 0;
}

//
// given a string of binary digits ('1' and '0')
// return the corresponding signed 16 bit integer
// Hint in course website states to use bit operation
// << (Shifts bits to the left) and | (or bit operation)
//
int16_t sixteen_in(char *bits) {
    int result = 0;
    for (int counter = 0; counter <= N_BITS; counter++) {
        if (bits[counter] == '1') {
            // add_on acts as binary number to be bit or into the result
            int add_on = 0;
            add_on = 1 << (N_BITS - counter - 1);
            result |= add_on;
        }
    }
    return result;
}

