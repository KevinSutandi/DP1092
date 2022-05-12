# Recursive factorial function
# n < 1 yields n! = 1
# $s0 is used for n
# we use an s register because the convention is their value
# is preserved across function calls
# f is in $t0

# DO NOT CHANGE THE CODE IN MAIN

main:
    addi $sp, $sp, -8  # create stack frame
    sw   $ra, 4($sp)   # save return address
    sw   $s0, 0($sp)   # save $s0

    li   $s0, 0
    la   $a0, msg1
    li   $v0, 4
    syscall            # printf(Enter n: ")

    li    $v0, 5
    syscall            # scanf("%d", &n)
    move  $s0, $v0

    move  $a0, $s0     # factorial(n)
    jal   factorial    #
    move  $t0, $v0     #

    move  $a0, $s0
    li    $v0, 1
    syscall            # printf ("%d", n)

    la    $a0, msg2
    li    $v0, 4
    syscall            # printf("! = ")

    move  $a0, $t0
    li    $v0, 1
    syscall            # printf ("%d", f)

    li   $a0, '\n'     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $s0, 0($sp)   # restore $s0
    lw   $ra, 4($sp)   # restore $ra
    addi $sp, $sp, 8   # restore sp

    li  $v0, 0         # return 0
    jr  $ra

    .data
msg1:   .asciiz "Enter n: "
msg2:   .asciiz "! = "


# DO NOT CHANGE CODE ABOVE HERE


    .text
factorial:
    #  ADD CODE TO CREATE STACK FRAME
    addi $sp, $sp, -8
    sw   $ra, 0($sp)
    sw   $s0, 4($sp)

    # ADD CODE FORFUNCTION HERE
    move $s0, $a0           # move n to $s0
    li   $t0, 1             # int result
    li   $t1, 1             # load 1 into $t1

if:
    ble $s0, $t1, else      # if n <= 1, jump to else
    addi $t2, $s0, -1       # t2 = n - 1
    move $a0, $t2           # a0 = n - 1
    jal factorial           # call factorial(n - 1)
    move $t3, $v0           # t3 = factorial(n - 1)
    mul $t0, $s0, $t3       # result = n * factorial(n - 1)
    j factorial_epilogue    # jump to factorial_epilogue

else: 
    li $t0, 1               # result = 1
    j factorial_epilogue    # jump to factorial_epilogue

    # ADD CODE TO REMOVE STACK FRAME
factorial_epilogue:
    move $v0, $t0           # return result

    lw   $ra, 0($sp)
    lw   $s0, 4($sp)
    addi $sp, $sp, 8
    jr  $ra
