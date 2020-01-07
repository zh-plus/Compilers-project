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
fact:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    move $t0, $a0
    li $t1, 1
    beq $t0, $t1, label1
    j label2
label1:
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t0
    jr $ra
label2:
    addi $t2, $t0, -1
    move $a0, $t2
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal fact
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $t2, ($sp)
    addi $sp, $sp, 4
    lw $t1, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $t3, $v0
    mul $t4, $t0, $t3
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t4
    jr $ra
main:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal read
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t5, $v0
    move $t6, $t5
    bgt $t6, $t1, label3
    j label4
label3:
    move $a0, $t6
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
    jal fact
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
    move $s0, $t7
    j label5
label4:
    li $s0, 1
label5:
    move $a0, $s0
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s0, $v0
    li $s1, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $s1
    jr $ra
