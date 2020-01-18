	.data
str:		.space 	40
prompt:	.asciiz	"Enter a hexadecimal number: "
error:	.asciiz 	"Invalid hexadecimal number.\n"

	.text
	.globl main
main:
	addiu	$sp, $sp, -20
	sw		$ra, 20($sp)
	
while:
	la		$a0, prompt
	la		$a1, str
	li		$a2, 40
	jal	InputConsoleString
	
	
	la		$a0, 16($sp)
	la		$a1, str
	jal 	axtoi
	
	bnez	$v0, ifElse
	la		$a0, error
	jal	PrintString
	b 		endIf
ifElse:
	lw		$a0, 16($sp)
	jal	PrintInteger
	b 		endWhile
endIf:
	b 		while
	
endWhile:
	lw		$ra, 20($sp)
	addiu	$sp, $sp, 8
	
	li		$v0, 0
	jr		$ra
	
	.include	"./util.s"