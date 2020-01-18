.data
	x: .word 1
	y: .word 2
.text
.globl main
main:
	lw $t0, x
	lw $t1, y
	add $a0, $t1, $t0
	
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall