	.data
prompt:		.asciiz	"Enter number: "
positive: 	.asciiz	"positive"
negative:	.asciiz	"negative"
zero:		.asciiz	"zero"
	.text
	.globl main
main: 
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall
	bltz	$v0, ltz
	beqz	$v0, else
	li	$v0, 4
	la	$a0, positive
	syscall
	b	end
ltz:
	li	$v0, 4
	la	$a0, negative
	syscall
	b	end
else:
	li	$v0, 4
	la	$a0, zero
	syscall
end:
	jr	$ra