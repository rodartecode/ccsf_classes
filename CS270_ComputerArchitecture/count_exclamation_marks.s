		.data
sentence:	.asciiz "holy crap!!!!"

		.text
		.globl main
main:
	li 	$t0, 0			# Count
	la	$t1, sentence		# String address
	lb	$t2, ($t1)
For:	
	beqz	$t2, endFor
	
	bne	$t2, 33, endIf		# not exclamation, skip if
	addi	$t0, $t0, 1		# its exclamation, increment count
endIf:
	# Increment interator, load new byte ##############
	addi	$t1, $t1, 1
	lb	$t2, ($t1)
	b	For
endFor:
	li	$v0, 1
	move	$a0, $t0
	syscall
	jr	$ra