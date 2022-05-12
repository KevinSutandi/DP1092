// Write a C Program, read_students_file.c, which takes a filename as an arg
// Made by Kevin Edbert Sutandi (z5352065)
// Date 10/03/2022

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "student.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Incorrect usage %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "%s: Could not open file %s: ", argv[0], argv[1]);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct student students;

    while (fread(&students, sizeof(struct student), 1, fp)) {
        printf("%d %s %s \n", students.id, students.name, students.program);
    }

    fclose(fp);
    return 0;
}