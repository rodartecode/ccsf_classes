			.data
prefix:	.asciiz "You typed: "
prompt:	.asciiz "Enter a string: "
			.text
			.globl main
main:
	addiu	$sp, $sp, -44
	sw		$ra, 4($sp)



	la		$a0, 44($sp)
	li		$a1, 40
	jal	generate_echo_string



	lw		$ra, 4($sp)
	addiu	$sp, $sp, 44
	li		$v0, 0
	jr		$ra
	
	# a0 = address
	# a1 = length
generate_echo_string:
	addiu $sp, $sp, -28
	sw		$ra, 16($sp)
	sw		$a0, 24($sp)
	sw		$a1, 28($sp)
	
	lw		$t9, 28($sp)
	addi	$t9, $t9, -1
	li		$t8, 0
	sw		$t8, ($a0)
	
	la		$a0, prefix
	jal 	strlen
	sw		$v0, 20($sp)
	
	lw		$a0, 24($sp)
	la		$a1, prefix
	lw		$a2, 28($sp)
	addi	$a2, $a2, -1
	jal	strncpy
	
	lw		$t9, 20($sp)
	lw		$t8, 28($sp)
	blt	$t9, $t8, endIf
	
	lw		$ra, 16($sp)
	addiu	$sp, $sp, 28
	li		$v0, 0
	jr		$ra
endIf:
	
	lw		$t9, 24($sp)
	lw		$t8, 20($sp)
	add	$a1, $t9, $t8
	la		$a0, prompt
	lw		$t9, 28($sp)
	sub	$a2, $t9, $t8
	jal	InputConsoleString
	
	lw		$ra, 16($sp)
	addiu	$sp, $sp, 28
	li		$v0, 0
	jr		$ra
	
		.include "util.s"