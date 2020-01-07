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
    li $t0, 110
    li $t1, 97
    li $t2, 3
    sub $t3, $t0, $t1
    li $t4, 2
    mul $t5, $t2, $t4
    add $t6, $t3, $t5
    move $t2, $t6
    move $t7, $t2
    move $a0, $t7
    addi $sp, $sp, -4
    sw $ra, ($sp)
    jal write
    lw $ra, ($sp)
    addi $sp, $sp, 4
    move $t7, $v0
    li $s0, 0
    addi $sp, $fp, 4
    lw $fp, -4($sp)
    move $v0, $s0
    jr $ra
