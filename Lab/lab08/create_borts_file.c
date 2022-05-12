// Write a C program, create_borts_file, which takes 3 arguments:
// 1. a filename
// 2. the beginning of a range of integers
// 3. the end of a range of integers
// Made by Kevin Edbert Sutandi (z5352065)
// Date 09/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define minimal_int 0
#define maximal_int 65535

int main(int argc, char *argv[]) {

    // Makes sure there are 3 arguments (not including the program name)
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <start> <end>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Declare variables and their values
    char *filename = argv[1];
    uint32_t start = atoi(argv[2]);
    uint32_t end = atoi(argv[3]);

    if (start < minimal_int || start > maximal_int) {
        fprintf(stderr, "Start must be between 0 and %d\n", maximal_int);
        exit(EXIT_FAILURE);
    }

    if (end < minimal_int || end > maximal_int) {
        fprintf(stderr, "End must be between 0 and %d\n", maximal_int);
        exit(EXIT_FAILURE);
    }

    // Open the file
    FILE *fp = fopen(filename, "w");

    // Check if the file is open
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the integers to the file
    for (uint32_t i = start; i <= end; i++) {
        for (int counter = 1; counter >= 0; counter--) {
            uint8_t byte = i >> (counter * 8) & 0xFF;
            fputc(byte, fp);
        }
    }
    // Close the file
    fclose(fp);
    
    return 0;
}
