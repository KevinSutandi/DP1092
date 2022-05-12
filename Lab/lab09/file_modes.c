// We would like to print the access permissions for a set of files
// Write a C program, file_modes.c, which is given one or more pathnames as 
// command line arguments. It should print one line for each pathnames which 
// gives the permissions of the file or directory.
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date: 15/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> <file2> ... <filesomething>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        struct stat file_stat;
        if (stat(argv[i], &file_stat) == -1) {
            perror(argv[i]);
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(file_stat.st_mode)) {
            printf("%c", 'd');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IRUSR) {
            printf("%c", 'r');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IWUSR) {
            printf("%c", 'w');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IXUSR) {
            printf("%c", 'x');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IRGRP) {
            printf("%c", 'r');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IWGRP) {
            printf("%c", 'w');
        } else {
            printf("%c", '-');
        }   

        if (file_stat.st_mode & S_IXGRP) {
            printf("%c", 'x');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IROTH) {
            printf("%c", 'r');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IWOTH) {
            printf("%c", 'w');
        } else {
            printf("%c", '-');
        }

        if (file_stat.st_mode & S_IXOTH) {
            printf("%c", 'x');
        } else {
            printf("%c", '-');
        }

        printf(" %s\n", argv[i]);
    }
    
}