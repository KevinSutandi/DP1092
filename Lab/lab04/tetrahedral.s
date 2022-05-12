#// Read a number n and print the first n tetrahedral numbers
#// https://en.wikipedia.org/wiki/Tetrahedral_number
#
##include <stdio.h>
#int main(void) {
#  int i, j, n, total, how_many;
#
#    printf("Enter how many: ");
#    scanf("%d", &how_many);3
#
#    n = 1;
#
#    while (n <= how_many) {
#        total = 0;
#        j = 1;
#
#        while (j <= n) {
#            i = 1;
#            while (i <= j) {
#                total = total + i;
#                i = i + 1;
#            }
#            j = j + 1;
#        }
#        printf("%d\n", total);
#        n = n + 1;
#    }
#    return 0;
#}



# Read a number n and print the first n tetrahedral numbers
# https://en.wikipedia.org/wiki/Tetrahedral_number
#MIPS Tetahedral
#Made by Kevin Edbert Sutandi (z5352065)
#Date 09/February/2022


    .text
    .globl main

main:                                   # int main(void) {

    la   $a0, prompt                    # printf("Enter how many: ");
    li   $v0, 4
    syscall

    li   $v0, 5                         # scanf("%d", number);
    syscall
    move $s0, $v0                       # save number in $s0

    li   $s1, 1                         # int n = 1;

loop1:
    bgt  $s1, $s0, end                  # while (n <= how_many) {
    li   $s2, 0                         # int total = 0;
    li   $s3, 1                         # int j = 1;

loop2:
    bgt  $s3, $s1, counter_next_n       # while (j <= n) {
    li   $s4, 1                         # int i = 1;

loop3:
    bgt  $s4, $s3, counter_next_j       # while (i <= j) {
    add  $s2, $s2, $s4                  # total = total + i; 
    addi $s4, $s4, 1                    # i = i + 1;
    j loop3;

counter_next_j:
    addi $s3, $s3, 1                    # j = j + 1;
    j loop2;

counter_next_n:
    move $a0, $s2                       # printf("%d", total);
    li   $v0, 1
    syscall

    la  $a0, new_line                   # printf("\n");
    li  $v0, 4
    syscall

    add $s1, $s1, 1                     # n = n + 1;
    j loop1;                            # goto loop1

end:
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter how many: "

new_line: 
    .asciiz "\n"
