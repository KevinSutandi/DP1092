#C Code For Reference
#// Read 10 numbers into an array
#// print 0 if they are in non-decreasing order
#// print 1 otherwise
#
##include <stdio.h>
#
#int main(void) {
#    int i;
#    int numbers[10] = { 0 };
#
#    i = 0;
#    while (i < 10) {
#        scanf("%d", &numbers[i]);
#        i++;
#    }
#
#    int swapped = 0;
#    i = 1;
#    while (i < 10) {
#        int x = numbers[i];
#        int y = numbers[i - 1];
#        if (x < y) {
#            swapped = 1;
#        }
#        i++;
#    }
#
#    printf("%d\n", swapped);
#}

# MIPS Unordered
# Made by Kevin Edbert Sutandi
# Date : 16 February 2022


# Read 10 numbers into an array
# print 0 if they are in non-decreasing order
# print 1 otherwise

# i in register $t0

main:

    li   $t0, 0         # i = 0
loop0:
    bge  $t0, 10, end0  # while (i < 10) {

    li   $v0, 5         #   scanf("%d", &numbers[i]);
    syscall             #

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    sw   $v0, ($t3)     #   store entered number in array

    addi $t0, $t0, 1    #   i++;
    j    loop0          # }
end0:
    li   $t4, 0         # int swapped = 0;
    li   $t0, 0         # i = 0
loop1:
    bge  $t0, 10, end1  # while (i < 10) {

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #   &numbers[i]
    add  $t3, $t1, $t2  #   &numbers[i]
    lw   $t5, ($t3)     #   int x = numbers[i];

    mul $t1, $t0, 4     #   calculate &numbers[i - 1]
    la  $t2, numbers    #   &numbers[i]
    add $t3, $t1, $t2   #   &numbers[i]
    addi $t3, $t3, -4   #   &numbers[i - 1]
    lw  $t6, ($t3)      #   int y = numbers[i - 1];

    blt $t5, $t6, end2  #   if (x > y) {
    addi $t0, $t0, 1    #   i++
    j loop1             #   }

end1:
    move $a0, $t4       #   laod swapped into a0
    li   $v0, 1         #   printf("%d", swapped);
    syscall

    li   $a0, '\n'      # printf("%c", '\n');
    li   $v0, 11
    syscall

    jr   $ra

end2:
    li $t4, 1           # swapped = 1;
    addi $t0, $t0, 1    # i++
    j loop1

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

