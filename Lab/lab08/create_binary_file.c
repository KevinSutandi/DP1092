// Write a program that reads from a file
// and writes integers from a range of 0 to 255 inclusive specifying byte values
// to a file.
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date: 09/03/2022

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Usage: %s <output file> <num1> <num2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int counter = 2;

    while (counter < argc) {
        int num = atoi(argv[counter]);
        if (num < 0 || num > 255) {
            fprintf(stderr, "Error: %d is not in range 0 to 255\n", num);
            exit(EXIT_FAILURE);
        }
        fputc(num, fp);
        counter++;
    }
}