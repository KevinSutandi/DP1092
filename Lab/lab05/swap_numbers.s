# read 10 numbers into an array
# swap any pairs of of number which are out of order
# then print the 10 numbers

# i in register $t0,
# registers $t1 - $t3 used to hold temporary results

# Adding this block of code to the file
#    i = 1;
#    while (i < 10) {
#        int x = numbers[i];
#        int y = numbers[i - 1];
#        if (x < y) {
#            numbers[i] = y;
#            numbers[i - 1] = x;
#        }
#        i++;
#    }


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

    li $t0, 1           # i = 1
loop1: 
    bge $t0, 10, end1   # while (i < 10) {

    mul $t1, $t0, 4     #   int x = numbers[i];
    la  $t2, numbers    #
    add $t3, $t1, $t2   #
    lw  $t4, ($t3)      #  

    addi $t5, $t0, -1   #   int y = numbers[i - 1];
    mul $t6, $t5, 4     #
    la  $t7, numbers    #
    add $t8, $t6, $t7   #
    lw  $t9, ($t8)      # 

    bge $t4, $t9, next  #   if (numbers[i] < numbers[i - 1]) {
    sw $t9, ($t3)       #    swap numbers
    sw $t4, ($t8)       #   }

next:
    addi $t0, $t0, 1    #   i++;
    j loop1             # }

end1:

    li   $t0, 0         # i = 0
loop2:
    bge  $t0, 10, end2  # while (i < 10) {

    mul  $t1, $t0, 4    #   calculate &numbers[i]
    la   $t2, numbers   #
    add  $t3, $t1, $t2  #
    lw   $a0, ($t3)     #   load numbers[i] into $a0
    li   $v0, 1         #   printf("%d", numbers[i])
    syscall

    li   $a0, '\n'      #   printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t0, $t0, 1    #   i++
    j    loop2          # }

end2:
    li   $v0, 0
    jr   $ra            # return 0

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

