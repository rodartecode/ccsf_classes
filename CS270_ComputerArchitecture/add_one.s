	.data
	
	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw		$ra, 4($sp)
	
	li 	$a0, 9
	jal	add_one
	
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
	
	
	.include	"./util.s"