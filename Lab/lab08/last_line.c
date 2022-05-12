// Write a C program, last_line, which takes one argument, a filename, 
// and which should print the last line of that file.
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date: 10/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int back = -2;
    while (fseek(fp, back, SEEK_END) == 0 && fgetc(fp) != '\n') {
        back--;
    }

    fseek(fp, back + 1, SEEK_END);
    int counter;
    while ((counter = fgetc(fp)) != EOF) {
        printf("%c", counter);
    }

    fclose(fp);
    return 0;

}