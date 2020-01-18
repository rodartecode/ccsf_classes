	.data
prompt:		.asciiz "Enter number: "
	.text
	.globl 	main
main:
	la	$a0, prompt
	li	$v0, 4
	syscall
	li	$v0, 5
	syscall
	blez	$v0, end
	move	$t0, $v0
	li 	$v0, 1
	li	$a0, 1
begin:
	bgt	$a0, $t0, end
	syscall
	addi	$a0, $a0, 1
	b	begin	
end:
	jr	$ra
