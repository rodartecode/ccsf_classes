.data
	a: .word 5
	b: .word 2
	c: .word 3
	d: .word 6
.text
.globl main
main:
	lw $a0, a
	lw $t0, b
	lw $t1, c
	lw $t2, d
	sll $a0, $a0, 8
	add $a0, $a0, $t0
	sll $a0, $a0, 8
	add $a0, $a0, $t1
	sll $a0, $a0, 8
	add $a0, $a0, $t2
	li $v0, 1
	syscall
	li $v0, 10
	syscall