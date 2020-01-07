.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
    li $v0, 4
    la $a0, _prompt
    syscall
    li $v0, 5
    syscall
    jr $ra
write:
    li $v0, 1
    syscall
    li $v0, 4
    la $a0, _ret
    syscall
    move $v0, $0
    jr $ra
hanoi:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    move $t0, $a0
    move $t1, $a1
    move $t2, $a2
    move $t3, $a3
    move $t4, $t0
    li $t5, 1
    beq $t4, $t5, label0
    j label1
label0:
    move $t6, $t1
    li $t7, 10000
    mul $s0, $t6, $t7
    move $s1, $t3
    add $s2, $s0, $s1
    move $a0, $s2
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s2, $v0
    j label2
label1:
    move $s3, $t0
    li $s4, 1
    sub $s5, $s3, $s4
    move $s6, $t1
    move $s7, $t3
    move $t2, $t2
    move $a3, $t2
    move $a2, $s7
    move $a1, $s6
    move $a0, $s5
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    addi $sp, $sp, -4
    sw $t4, ($sp)
    addi $sp, $sp, -4
    sw $t5, ($sp)
    addi $sp, $sp, -4
    sw $t6, ($sp)
    addi $sp, $sp, -4
    sw $t7, ($sp)
    addi $sp, $sp, -4
    sw $s0, ($sp)
    addi $sp, $sp, -4
    sw $s1, ($sp)
    addi $sp, $sp, -4
    sw $s2, ($sp)
    addi $sp, $sp, -4
    sw $s3, ($sp)
    addi $sp, $sp, -4
    sw $s4, ($sp)
    addi $sp, $sp, -4
    sw $s5, ($sp)
    addi $sp, $sp, -4
    sw $s6, ($sp)
    addi $sp, $sp, -4
    sw $s7, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal hanoi
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $s7, ($sp)
    addi $sp, $sp, 4
    lw $s6, ($sp)
    addi $sp, $sp, 4
    lw $s5, ($sp)
    addi $sp, $sp, 4
    lw $s4, ($sp)
    addi $sp, $sp, 4
    lw $s3, ($sp)
    addi $sp, $sp, 4
    lw $s2, ($sp)
    addi $sp, $sp, 4
    lw $s1, ($sp)
    addi $sp, $sp, 4
    lw $s0, ($sp)
    addi $sp, $sp, 4
    lw $t7, ($sp)
    addi $sp, $sp, 4
    lw $t6, ($sp)
    addi $sp, $sp, 4
    lw $t5, ($sp)
    addi $sp, $sp, 4
    lw $t4, ($sp)
    addi $sp, $sp, 4
    lw $t3, ($sp)
    addi $sp, $sp, 4
    lw $t2, ($sp)
    addi $sp, $sp, 4
    lw $t1, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $t4, $v0
    move $t5, $t1
    li $t6, 10000
    mul $t7, $t5, $t6
    move $s0, $t3
    add $s1, $t7, $s0
    move $a0, $s1
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s1, $v0
    move $s2, $t0
    li $s3, 1
    sub $s4, $s2, $s3
    move $t2, $t2
    move $s7, $t1
    move $s6, $t3
    move $a3, $s6
    move $a2, $s7
    move $a1, $t2
    move $a0, $s4
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    addi $sp, $sp, -4
    sw $t4, ($sp)
    addi $sp, $sp, -4
    sw $t5, ($sp)
    addi $sp, $sp, -4
    sw $t6, ($sp)
    addi $sp, $sp, -4
    sw $t7, ($sp)
    addi $sp, $sp, -4
    sw $s0, ($sp)
    addi $sp, $sp, -4
    sw $s1, ($sp)
    addi $sp, $sp, -4
    sw $s2, ($sp)
    addi $sp, $sp, -4
    sw $s3, ($sp)
    addi $sp, $sp, -4
    sw $s4, ($sp)
    addi $sp, $sp, -4
    sw $s5, ($sp)
    addi $sp, $sp, -4
    sw $s6, ($sp)
    addi $sp, $sp, -4
    sw $s7, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal hanoi
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $s7, ($sp)
    addi $sp, $sp, 4
    lw $s6, ($sp)
    addi $sp, $sp, 4
    lw $s5, ($sp)
    addi $sp, $sp, 4
    lw $s4, ($sp)
    addi $sp, $sp, 4
    lw $s3, ($sp)
    addi $sp, $sp, 4
    lw $s2, ($sp)
    addi $sp, $sp, 4
    lw $s1, ($sp)
    addi $sp, $sp, 4
    lw $s0, ($sp)
    addi $sp, $sp, 4
    lw $t7, ($sp)
    addi $sp, $sp, 4
    lw $t6, ($sp)
    addi $sp, $sp, 4
    lw $t5, ($sp)
    addi $sp, $sp, 4
    lw $t4, ($sp)
    addi $sp, $sp, 4
    lw $t3, ($sp)
    addi $sp, $sp, 4
    lw $t2, ($sp)
    addi $sp, $sp, 4
    lw $t1, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $s5, $v0
label2:
    li $t4, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t4
    jr $ra
main:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    li $t5, 3
    move $t6, $t5
    move $t7, $t6
    li $s0, 1
    li $s1, 2
    li $t0, 3
    move $a3, $t0
    move $a2, $s1
    move $a1, $s0
    move $a0, $t7
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    addi $sp, $sp, -4
    sw $t4, ($sp)
    addi $sp, $sp, -4
    sw $t5, ($sp)
    addi $sp, $sp, -4
    sw $t6, ($sp)
    addi $sp, $sp, -4
    sw $t7, ($sp)
    addi $sp, $sp, -4
    sw $s0, ($sp)
    addi $sp, $sp, -4
    sw $s1, ($sp)
    addi $sp, $sp, -4
    sw $s2, ($sp)
    addi $sp, $sp, -4
    sw $s3, ($sp)
    addi $sp, $sp, -4
    sw $s4, ($sp)
    addi $sp, $sp, -4
    sw $s5, ($sp)
    addi $sp, $sp, -4
    sw $s6, ($sp)
    addi $sp, $sp, -4
    sw $s7, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal hanoi
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $s7, ($sp)
    addi $sp, $sp, 4
    lw $s6, ($sp)
    addi $sp, $sp, 4
    lw $s5, ($sp)
    addi $sp, $sp, 4
    lw $s4, ($sp)
    addi $sp, $sp, 4
    lw $s3, ($sp)
    addi $sp, $sp, 4
    lw $s2, ($sp)
    addi $sp, $sp, 4
    lw $s1, ($sp)
    addi $sp, $sp, 4
    lw $s0, ($sp)
    addi $sp, $sp, 4
    lw $t7, ($sp)
    addi $sp, $sp, 4
    lw $t6, ($sp)
    addi $sp, $sp, 4
    lw $t5, ($sp)
    addi $sp, $sp, 4
    lw $t4, ($sp)
    addi $sp, $sp, 4
    lw $t3, ($sp)
    addi $sp, $sp, 4
    lw $t2, ($sp)
    addi $sp, $sp, 4
    lw $t1, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $s2, $v0
    li $s3, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $s3
    jr $ra
