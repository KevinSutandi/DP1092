.data
vec: .word 1, 2, 3, 4, 5, 6, 7, 8

.text
main:
    lw $t0, vec+8
    lw $t1, vec+4
    lw $t2, vec+0
    add $t0, $t0, $t1
     