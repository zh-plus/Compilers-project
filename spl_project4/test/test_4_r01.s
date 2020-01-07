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
    beq $t4, $t5, label0
    j label1
label0:
    lw $t1, 16($sp)
    move $t0, $t1
    li $t2, 10000
    mul $t3, $t0, $t2
    lw $t5, 8($sp)
    move $t4, $t5
    add $t6, $t3, $t4
    move $a0, $t6
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t6, $v0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    addi $sp, $sp, -4
    sw $t4, ($sp)
    addi $sp, $sp, -4
    sw $t6, ($sp)
    j label2
label1:
    lw $t1, 40($sp)
    move $t0, $t1
    li $t2, 1
    sub $t3, $t0, $t2
    lw $t5, 36($sp)
    move $t4, $t5
    lw $t7, 28($sp)
    move $t6, $t7
    lw $s1, 32($sp)
    move $s0, $s1
    move $a3, $s0
    move $a2, $t6
    move $a1, $t4
    move $a0, $t3
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
    sw $ra, ($sp)
    jal hanoi
    lw $ra, ($sp)
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
    move $s3, $t5
    li $s4, 10000
    mul $s5, $s3, $s4
    move $s6, $t7
    add $s7, $s5, $s6
    move $a0, $s7
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s7, $v0
    addi $sp, $sp, -4
    sw $s2, ($sp)
    move $s2, $t1
    li $s2, 1
    addi $sp, $sp, -4
    sw $s2, ($sp)
    sub $s2, $s2, $s2
    move $s2, $s1
    addi $sp, $sp, -4
    sw $s2, ($sp)
    move $s2, $t5
    move $s2, $t7
    move $a3, $s2
    move $a2, $s2
    move $a1, $s2
    move $a0, $s2
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
    addi $sp, $sp, -4
    sw $s2, ($sp)
    move $s2, $v0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    addi $sp, $sp, -4
    sw $t4, ($sp)
    addi $sp, $sp, -4
    sw $t6, ($sp)
    addi $sp, $sp, -4
    sw $s0, ($sp)
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
label2:
    li $t0, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t0
    jr $ra
main:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    li $t1, 2
    move $t2, $t1
    move $t3, $t2
    li $t4, 1
    li $t5, 2
    li $t6, 3
    move $a3, $t6
    move $a2, $t5
    move $a1, $t4
    move $a0, $t3
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
    sw $ra, ($sp)
    jal hanoi
    lw $ra, ($sp)
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
    move $t7, $v0
    li $s0, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $s0
    jr $ra
