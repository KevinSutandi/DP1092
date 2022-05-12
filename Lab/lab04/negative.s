# negative.s
#int main(void){
#    int n;
#    printf("Enter a number: ");
#    scanf("%d",&n);
#    if( n > 0 ){
#        printf("You have entered a positive number.\n");
#    } else if ( n < 0){
#        printf("Don't be so negative!\n");
#    } else {
#        printf("You have entered zero.\n");
#    } 
#    return 0;
#}
### Global data

#MIPS Negative
#Made by Kevin Edbert Sutandi (z5352065)
#Date 08/February/2022

   .data

input_msg:
   .asciiz "Enter a number: "
positive_msg:
   .asciiz "You have entered a positive number.\n"
zero_msg:
   .asciiz "You have entered zero.\n"
negative_msg:
   .asciiz "Don't be so negative!\n"


### main() function
   .text
   .globl main

main:
   la    $a0, input_msg
   li    $v0, 4
   syscall                  # printf("Enter a number: ");

   li    $v0, 5
   syscall                  # scanf("%d", into $v0)
   move $s0, $v0            # store n in $s0

   beqz  $s0, zero          # if n == 0, goto zero
   bgez  $s0, positive      # if n > 0, goto positive
   bltz  $s0, negative      # if n < 0, goto negative

positive:
   la    $a0, positive_msg  # load positive_msg into $a0
   li    $v0, 4             # print the positive_msg string
   syscall                  # syscall
   j end                    # jump to end

negative:
   la    $a0, negative_msg  # load negative_msg into $a0
   li    $v0, 4             # print the negative_msg string
   syscall                  # syscall
   j end                    # jump to end

zero:
   la    $a0, zero_msg      # load zero_msg into $a0
   li    $v0, 4             # print the zero_msg string
   syscall                  # syscall
   j end                    # jump to end  

end:
   li    $v0, 0             # return 0
   jr    $ra                # jump to main

