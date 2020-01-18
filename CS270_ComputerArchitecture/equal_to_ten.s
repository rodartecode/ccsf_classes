	.data
prompt:	.asciiz	"Enter number: "
ten:	.asciiz "Ten!"
	.text
	.globl	main
main:
	la	$a0, prompt
	li	$v0, 4
	syscall
	li	$v0, 5
	syscall
	bne	$v0, 10, end
	la	$a0, ten
	li 	$v0, 4
	syscall
end:
	jr	$ra