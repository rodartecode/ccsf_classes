.data
	input: .asciiz "Enter number: "
.text
.globl main
main:
	la $a0, input
	
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	move $t1, $v0
	
	add $a0, $t1, $t0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
	