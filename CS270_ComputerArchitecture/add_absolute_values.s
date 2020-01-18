		.data
array:		.word 1, -4, -555
array_size:	.word 3

		.text
		.globl main
main:
	li 	$t0, 0			# Count
	lw	$t1, array_size		# array size
	li	$t2, 0			# iterator
	la	$t4, array		# array address
	lw	$t3, ($t4)		# load byte
For:	
	bge	$t2, $t1, endFor	# check loop conditional
	
	bgez	$t3, endIf		# greater than zero, skip if
	move	$t5, $t3		# less than zero, store word value
	add	$t5, $t5, $t5		# double the value
	sub	$t3, $t3, $t5		# 'subtract' from orginal word value, should give abs value
endIf:
	add	$t0, $t0, $t3		# add to sum
	# Increment interator, load new word ##############
	addi	$t2, $t2, 1
	addi	$t4, $t4, 4
	lw	$t3, ($t4)
	b	For
endFor:
	li	$v0, 1
	move	$a0, $t0
	syscall
	jr	$ra