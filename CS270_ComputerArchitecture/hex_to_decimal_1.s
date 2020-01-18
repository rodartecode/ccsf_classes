	.data
str:		.space 	40
prompt:	.asciiz	"Enter a hexadecimal number: "

	.text
	.globl main
main:
	addiu	$sp, $sp, -20
	sw		$ra, 20($sp)
	
	la		$a0, prompt
	la		$a1, str
	li		$a2, 40
	jal	InputConsoleString
	
	
	la		$a0, 16($sp)
	la		$a1, str
	jal 	axtoi
	
	lw		$a0, 16($sp)
	jal	PrintInteger
	
	lw		$ra, 20($sp)
	addiu	$sp, $sp, 8
	
	li		$v0, 0
	jr		$ra
	
	.include	"./util.s"