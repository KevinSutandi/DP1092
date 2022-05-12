// Write a C program, create_integers_file, which takes 3 arguments:
// 1. a filename
// 2. the beginning of a range of integers
// 3. the end of a range of integers
// Made by Kevin Edbert Sutandi (z5352065)
// Date 09/03/2022

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Makes sure there are 3 arguments (not including the program name)
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <start> <end>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Declare variables and their values
    char *filename = argv[1];
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    // Open the file
    FILE *fp = fopen(filename, "w");

    // Check if the file is open
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the integers to the file
    for (int i = start; i <= end; i++) {
        fprintf(fp, "%d\n", i);
    }

    // Close the file
    fclose(fp);
    
    return 0;
}

