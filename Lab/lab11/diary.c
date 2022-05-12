// Maintain a simple diary in the file $HOME/./diary
// Appends 1 line to the diary file.
//
// Made by Kevin Edbert Sutandi (z5352065)
// Date : 30 March 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX 100

int main(int argc, char *argv[]) {
    char *home = getenv("HOME");
    if (home == NULL) {
        printf("Error: $HOME not set\n");
        exit(EXIT_FAILURE);
    }

    char *diary_file = "/.diary";
    strcat(home, diary_file);

    FILE *diary = fopen(home, "a");
    if (diary == NULL) {
        perror(home);
        exit(EXIT_FAILURE);
    }

    for (int counter = 1; counter < argc; counter++) {
        fprintf(diary, "%s ", argv[counter]);
        if (counter == argc - 1) {
            fprintf(diary, "\n");
        }
    }
    fclose(diary);
    return 0;
}