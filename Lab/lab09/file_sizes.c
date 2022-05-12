// Write a C program, file_sizes.c, which is given one or more filenames as 
// command line arguments.
// Made by Kevin Edbert Sutandi (z5352065) 
// Date : 15/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> <filename2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long int total = 0;
    for (int i = 1; i < argc; i++) {
        struct stat sb;
        if (stat(argv[i], &sb) == -1) {
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("%s: %ld bytes\n", argv[i], sb.st_size);
        total = total + sb.st_size;
    }
    printf("Total: %ld bytes\n", total);


}
