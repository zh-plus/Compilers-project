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
    addi $sp, $sp, -4
    sw $t0, ($sp)
    beq $t0, $t1, label1
    j label2
label1:
    lw $t0, ($sp)
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t0
    jr $ra
label2:
    addi $t1, $t0, -1
    move $a0, $t1
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal fact
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $t1, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $t2, $v0
    mul $t3, $t0, $t2
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t3
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
    move $t4, $v0
    move $t5, $t4
    li $t6, 1
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
    bgt $t5, $t6, label3
    j label4
label3:
    lw $t0, ($sp)
    move $a0, $t0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal fact
    lw $ra, ($sp)
    addi $sp, $sp, 4
    lw $t0, ($sp)
    addi $sp, $sp, 4
    move $t1, $v0
    move $t2, $t1
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    j label5
label4:
    lw $t0, ($sp)
    li $t0, 1
    sw $t0, ($sp)
label5:
    lw $t0, ($sp)
    move $a0, $t0
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t0, $v0
    li $t1, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t1
    jr $ra
