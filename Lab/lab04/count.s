# read a number n and print the integers 1..n one per line
#MIPS Counting
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
    move $s0, $v0           # number = scanf("%d", number);

    li   $s1, 1             # int counter = 1;

wego:
    bgt $s1, $s0, end       # if (counter > number) goto end;

    move  $a0, $s1
    li    $v0, 1    
    syscall                 # printf("%d", counter);

    la  $a0, new_line       # printf("\n");
    li  $v0, 4
    syscall


    addi $s1, $s1, 1        # counter++;
    j    wego
end:
    jr   $ra                # return

    .data
prompt:
    .asciiz "Enter a number: "
