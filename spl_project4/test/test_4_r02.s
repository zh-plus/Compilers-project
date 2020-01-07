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
main:
    addi $sp, $sp, -4
    sw $fp, ($sp)
    move $fp, $sp
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal read
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t0, $v0
    move $t1, $t0
    move $t2, $t1
    li $t3, 0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    addi $sp, $sp, -4
    sw $t3, ($sp)
    bgt $t2, $t3, label0
    j label1
label0:
    li $t0, 1
    move $a0, $t0
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t0, $v0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    j label2
label1:
    lw $t1, 12($sp)
    move $t0, $t1
    li $t2, 0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t2, ($sp)
    blt $t0, $t2, label3
    j label4
label3:
    li $t0, 1
    li $t2, 0
    sub $t1, $t2, $t0
    move $a0, $t1
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t1, $v0
    addi $sp, $sp, -4
    sw $t0, ($sp)
    addi $sp, $sp, -4
    sw $t1, ($sp)
    j label5
label4:
    li $t0, 0
    move $a0, $t0
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t0, $v0
    addi $sp, $sp, -4
    sw $t0, ($sp)
label5:
label2:
    li $t0, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $t0
    jr $ra
