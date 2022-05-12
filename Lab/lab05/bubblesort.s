# read 10 numbers into an array
# bubblesort them
# then print the 10 numbers

# i in register $t0
# registers $t1, $t2 & $t3 used to hold temporary results

main:

    li   $t0, 0             # i = 0
loop0:
    bge  $t0, 10, end0      # while (i < 10) {

    li   $v0, 5             #   scanf("%d", &numbers[i]);
    syscall                 #

    mul  $t1, $t0, 4        #   calculate &numbers[i]
    la   $t2, numbers       #
    add  $t3, $t1, $t2      #
    sw   $v0, ($t3)         #   store entered number in array

    addi $t0, $t0, 1        #   i++;
    j    loop0              # }
end0:

    li $t1, 1               # int swapped = 1;

swapped_loop:
    bne $t1, 1, end_swap    # while (swapped) {
    li $t1, 0               # swapped = 0;




end_swap:

    li   $t0, 0             # i = 0
loop2:
    bge  $t0, 10, end2      # while (i < 10) {

    mul  $t1, $t0, 4        #   calculate &numbers[i]
    la   $t2, numbers       #
    add  $t3, $t1, $t2      #
    lw   $a0, ($t3)         #   load numbers[i] into $a0
    li   $v0, 1             #   printf("%d", numbers[i])
    syscall

    li   $a0, '\n'          #   printf("%c", '\n');
    li   $v0, 11
    syscall

    addi $t0, $t0, 1        #   i++
    j    loop2              # }
end2:

    jr   $ra                # return

.data

numbers:
    .word 0 0 0 0 0 0 0 0 0 0  # int numbers[10] = {0};

