// Write C Program, hidden_strings, that read bytes and if it finds
// 4 bytes in a row containing printable characters, it should print
// the bytes, and any following bytes containing ASCII printable
// characters
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date 10/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

int main (int argc, char *argv[]) {

    // Check if there are at least 1 arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (counter = 1; counter < argc; counter++) {
        FILE *fp = fopen(argv[counter], "r");
        if (fp == NULL) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // Read bytes from file
        uint8_t buffer[3];
        int bytes = 0;

        while ((bytes = fread(buffer, sizeof(uint8_t), 3, fp)) != EOF) {
            // Check if the bytes are printable
            if (buffer[0] >= 32 && buffer[0] <= 126 &&
                buffer[1] >= 32 && buffer[1] <= 126 &&
                buffer[2] >= 32 && buffer[2] <= 126) {
                // Print the bytes
                printf("%c%c%c", buffer[0], buffer[1], buffer[2]);
            }
        }
        
    }




}