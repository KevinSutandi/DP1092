#// A simple C program that attempts to be punny
#
#include <stdio.h>
#
#int main(void) {
#    printf("I MIPS you!\n");
#
#    return 0;
#}

#Replicate the C code Above
#Made by Kevin Edbert Sutandi (z5352065)
#Date 05/February/2022

    .data       
msg:
    .asciiz "I MIPS you!"
newline:
    .asciiz "\n"

    .text
    .globl main
main:
    la  $a0,msg         # loads the text I MIPS YOU
    li  $v0,4           # loads the syscall number
    syscall             # calls the syscall

    la  $a0,newline     # loads '\n'
    syscall             # calls the syscall

    li  $v0,10          # return zero
    syscall             # calls the syscall
    jr  $ra             # return from main