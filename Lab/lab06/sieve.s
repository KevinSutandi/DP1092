# Sieve of Eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
# C CODE TO CONVERT
#int main(void) {
#    int i = 0;
#    while (i < 1000) {
#        prime[i] = 1;
#        i++;
#    }
#
#    i = 2;
#    while (i < 1000) {
#        if (prime[i]) {
#            printf("%d\n", i);
#            int j = 2 * i;
#            while (j < 1000) {
#                prime[j] = 0;
#                j = j + i;
#            }
#        }
#        i++;
#    }
#    return 0;
#}
#
# Made by Kevin Edbert Sutandi (z5352065)
# Date : 23/02/2022


main:

    li $t0 , 0                              # int i = 0;
    li $t1 , 1000                           # load 1000

while1:
    bge $t0, $t1, while2_prog               # while (i < 1000) {
    la  $t2 , prime                         # 
    add $t2 , $t2 , $t0                     # calculate address of prime[i]
    li  $t3 , 1                             # prime[i] = 1;
    sb  $t3 , 0($t2)                        # store 1

while1_end:
    addi $t0 , $t0 , 1                      # i++;
    j  while1                               # goto while1

while2_prog:
    li  $t0 , 2                             # i = 2;

while2:
    bge $t0, $t1, end                       # while (i < 1000) {
    la  $t2, prime                          # load prime into t2
    add $t2, $t2 , $t0                      # calculate address of prime[i]
    lb  $t3, 0($t2)                         # load prime[i] into t3
    bne $t3, 1, while2_increment_i          # if (prime[i]) {

    move $a0, $t0                           # printf("%d\n", i);
    li   $v0, 1                             # print integer
    syscall

    lw $a0, newline
    li $v0,11
    syscall                                 # printf("\n"); 

    li  $t4, 2                              # load 2 into t4
    mul $t4 , $t4 , $t0                     # j = 2 * i

while3:
    bge $t4 , $t1 , while2_increment_i      # if (j >= 1000) goto while2_end;
    la  $t2 , prime                         # load prime into t5
    add $t2 , $t2 , $t4                     # calculate address of prime[j]
    sb  $zero , 0($t2)                      # prime[j] = 0;

while3_end:
    add $t4 , $t4 , $t0                     # j = j + i
    j  while3                               # goto while3;


while2_increment_i:
    addi $t0 , $t0 , 1                      # i = i + 1;
    j while2                                # goto while2;

end:
    li $v0, 0                               # return 0
    jr $31

.data
prime:
    .space 1000
newline:
    .asciiz "\n"