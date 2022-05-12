# Read a number and print positive multiples of 7 or 11 < n
#MIPS Seven-Eleven
#Made by Kevin Edbert Sutandi (z5352065)
#Date 08/February/2022

    .data
new_line: .asciiz "\n"

    .text
    .globl main

main:                       # int main(void)
    la   $a0, prompt        # printf("Enter a number: ");
    li   $v0, 4
    syscall

    li   $v0, 5             # scanf("%d", number);
    syscall
    move $s0, $v0           # save number in $s0

    li   $s1, 1             # int counter = 1;

looper:
    bge $s1 $s0, end        # if counter > number , goto end

    rem $v0, $s1, 7         # if counter % 7 = 0; 
    beqz $v0, success       # if counter % 7 = 0 goto success;

    rem $v0, $s1, 11        # if counter % 11 = 0;
    beqz $v0, success       # if counter % 11 = 0 goto success;

    addi $s1, $s1, 1        # counter++;
    j looper                # goto looper
success:
    move $a0, $s1           # printf("%d", counter);
    li   $v0, 1
    syscall

    la  $a0, new_line       # printf("\n");
    li  $v0, 4
    syscall

    addi $s1, $s1, 1        # counter++;

    j looper                # goto looper

end:
    jr   $ra           # return

    .data
prompt:
    .asciiz "Enter a number: "
