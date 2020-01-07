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
    bgt $t2, $t3, label0
    j label1
label0:
    li $t4, 1
    move $a0, $t4
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t4, $v0
    j label2
label1:
    move $t5, $t1
    li $t6, 0
    blt $t5, $t6, label3
    j label4
label3:
    li $t7, 1
    li $s1, 0
    sub $s0, $s1, $t7
    move $a0, $s0
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s0, $v0
    j label5
label4:
    li $s2, 0
    move $a0, $s2
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $s2, $v0
label5:
label2:
    li $s3, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $s3
    jr $ra
