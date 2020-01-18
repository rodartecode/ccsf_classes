		.data
array:		.word 0, 12, 1, 4, 0, 0, 0, 0
array_size:	.word 8

		.text
		.globl main
main:
	li 	$t0, 0			# Count
	lw	$t1, array_size		# array size
	li	$t2, 0			# iterator
	la	$t4, array
	lb	$t3, ($t4)
For:	
	bge	$t2, $t1, endFor
	
	bnez	$t3, endIf		# not zero, skip if
	addi	$t0, $t0, 1		# its zero, increment count
endIf:
	# Increment interator, load new byte ##############
	addi	$t2, $t2, 1
	addi	$t4, $t4, 4
	lb	$t3, ($t4)
	b	For
endFor:
	li	$v0, 1
	move	$a0, $t0
	syscall
	jr	$ra