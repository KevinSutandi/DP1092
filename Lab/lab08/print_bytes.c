// C program that takes a file, and read the specified file and 
// Print one line for each byte of the file
// Should show the byte in decimal and hexadecimal
// And if possible the ascii printable char
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date 09/03/2022

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        // Open the file
        FILE *fp = fopen(argv[arg], "r");

        // If file is not found, print error message
        if (fp == NULL) {
            fprintf(stderr, "Error opening file %s\n", argv[arg]);
            exit(EXIT_FAILURE);
        }

        int ch;
        int counter = 0;
        while ((ch = fgetc(fp)) != EOF) {
            printf("byte %4d: %3d 0x%02x ", counter, ch, ch);
            if (ch >= 32 && ch <= 126) {
                printf("'%c'", ch);
            }
            printf("\n");
            counter++;
        }
        fclose(fp);
    }

    return 0;


}