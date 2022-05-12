#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

int main (void) {
    int fd = open("xyz", O_RDONLY);
    if (fd == -1) {
        perror(NULL);
        exit(1);
    } else {
        printf("File opened successfully\n");
    } 
}

