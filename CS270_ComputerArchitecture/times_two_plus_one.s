	.data
	
	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw		$ra, 4($sp)
	
	li 	$a0, -3
	jal	times_two_plus_one
	
	move	$a0, $v0
	li		$v0, 1
	syscall
	
	lw		$ra, 4($sp)
	addiu	$sp, $sp, 4
	
	li		$v0, 0
	jr		$ra
	
add_one:
	addi	$v0, $a0, 1
	jr		$ra
	
multiply_by_two:
	sll	$v0, $a0, 1
	jr		$ra
	
times_two_plus_one:
	addiu	$sp, $sp, -4
	sw		$ra, 4($sp)

	jal	multiply_by_two
	move	$a0, $v0
	jal	add_one
	
	lw		$ra, 4($sp)
	addiu	$sp, $sp, 4
	
	jr		$ra
	
	.include	"./util.s"