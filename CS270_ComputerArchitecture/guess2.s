#######################
# guess.s
# -------
# This program asks the user to enter a guess. It
# reprompts if the user's entry is either an invalid
# hexadecimal number or a valid hexadecimal number
# that is outside the range specified in the program
# by min and max.
#
	.data
	.align 2
min:       .word 1
max:       .word 10
num:       .word 9     # I'd recommend trying different values
                       # for this variable when testing.
msgintro:  .asciiz "Guess must be a hexadecimal number between "
msgand:    .asciiz " and "
msgend:    .asciiz "\nEnter your guess (or nothing to quit).\n"
msgnl:     .asciiz "\n"
msgwin:    .asciiz "Got it!"
msghigh:   .asciiz "Guess is too high."
msglow:    .asciiz "Guess is too low."
	.text
	.globl main
main:
    ##################
    # YOUR CODE HERE #
    ##################

    # Step 1: Build prompt.


    # Step 2: Repeatedly use GetGuess to get a guess
    # from the user and report if it is too high, too
    # low, or correct.
    
	# Make space for arguments and saved return address
	subi  $sp, $sp, 40
	sw    $ra, 16($sp)
	lw		$a0, min
	la		$a1, 25($sp) 
	jal	itoax
	lw		$a0, max
	la		$a1, 34($sp)
	jal	itoax
mainWhile:
	la		$a0, msgintro
	li		$v0, 4
	syscall
	la		$a0, 25($sp)
	syscall
	la		$a0, msgand
	syscall
	la		$a0, 34($sp)
	syscall
	la		$a0, msgend
	syscall

	lw		$a1, min
	lw		$a2, max
	jal	GetGuess
	bne	$v0, -1, continue
	b		endMainWhile
continue:
	lw 	$t0, num
	beq 	$v0, $t0, youGotIt
	bgt	$v0, $t0, greater
	la		$a0, msglow
	li		$v0, 4
	syscall
	la		$a0, msgnl
	syscall
	b		mainWhile
	
greater:
	la		$a0, msghigh
	li		$v0, 4
	syscall
	la		$a0, msgnl
	syscall
	b		mainWhile
youGotIt:
	la		$a0, msgwin
	li		$v0, 4
	syscall
	la		$a0, msgnl
	syscall
endMainWhile:

    # Return
	lw    $ra, 16($sp)
	addi  $sp, $sp, 40
	li		$v0, 0
	jr    $ra

################################
# GetGuess
################################
# int GetGuess(char * question, int min, int max)
    .data
invalid:    .asciiz "Not a valid hexadecimal number.\n"
badrange:   .asciiz "Guess not in range.\n"
    .text
    .globl  GetGuess
GetGuess:
	
	# Prologue ###########################################
	addiu	$sp, $sp, -40		# Stack Pointer
	
	move	$t8, $a1				# save min and max 
	move	$t9, $a2 			# arguments
	
	la		$t6, invalid		# invalid string
	la		$t7, badrange		# out of range string
	sw		$ra, 36($sp)		# saved ra value
	# End Prologue ########################################
	
	
	
	# While loop ##########################################
While:
	li		$t0, 0				# initialize bytesRead variable
	
	la		$a0, 16($sp)		# address to save string
	li		$a1, 16				# length of string
	li		$v0, 8				# read string sys-code
	syscall
	lb		$t4, ($a0)			# grab first char

	# Count bytes loop ####################################
For:
	beq	$t4, 10, EndFor	# byte is empty, end loop
	bge	$t0, 16, EndFor	# read 16 bytes, end loop
	
	addi	$t0, $t0, 1			# increment byte count
	addi	$a0, $a0, 1			# increment address
	lb		$t4, ($a0)			# new byte

	b		For
EndFor:
	# Count bytes end #####################################
	
	
	beqz	$t0, Zero				# if zero, return -1
	bne	$t0, 10, EndIfZero	# if newline, return -1
Zero:
	li		$v0, -1,
	b		EndWhile
EndIfZero:							# otherwise continue

	# axtoi call ##########################################
	la		$a0, 32($sp)
	la		$a1, 16($sp)
	jal	axtoi
	# end axtoi ###########################################

	beq	$v0, 1, EndIfStatus
	la		$a0, ($t6)				# load address of invalid string
	li		$v0, 4
	syscall
	b		Continue					# number was invalid, loop again
EndIfStatus:						# number was valid, continue
	
	lw		$t1, 32($sp)			# load the number
	blt	$t1, $t8, IfRange		# continue if within bounds
	ble	$t1, $t9, EndIfRange
	
IfRange:								# out of range number
	la	$a0, ($t7)					# address of out of range string
	li	$v0, 4
	syscall					
	b	Continue						# number out of range, loop again
EndIfRange:							# number is in range, continue

	move 	$v0, $t1
	b	EndWhile
Continue:
	b 	While
EndWhile:
	# End while ###########################################
	
	# Epilogue ############################################
	lw	$ra, 36($sp)
	addiu	$sp, $sp, 40
	# End epilogue ########################################
   jr      $ra
    


###################################
#     OTHER HELPER FUNCTIONS      #
###################################

#
# char * strdup2 (char * str1, char * str2)
# -----
# strdup2 takes two strings, allocates new space big enough to hold 
# of them concatenated (str1 followed by str2), then copies each 
# string to the new space and returns a pointer to the result.
#
# strdup2 assumes neither str1 no str2 is NULL AND that malloc
# returns a valid pointer.
    .globl  strdup2
strdup2:
    # $ra   at 28($sp)
    # len1  at 24($sp)
    # len2  at 20($sp)
    # new   at 16($sp)
    sub     $sp,$sp,32
    sw      $ra,28($sp)
    
    # save $a0,$a1
    # str1  at 32($sp)
    # str2  at 36($sp)
    sw      $a0,32($sp)
    sw      $a1,36($sp)
    
    # get the lengths of each string 
    jal     strlen
    sw      $v0,24($sp)

    lw      $a0,36($sp)
    jal     strlen
    sw      $v0,20($sp)

    # allocate space for the new concatenated string 
    add     $a0,$v0,1
    lw      $t0,24($sp)
    add     $a0,$a0,$t0
    jal     malloc
    
    sw      $v0,16($sp)

    # copy each to the new area 
    move    $a0,$v0
    lw      $a1,32($sp)
    jal     strcpy

    lw      $a0,16($sp)
    lw      $t0,24($sp)
    add     $a0,$a0,$t0
    lw      $a1,36($sp)
    jal     strcpy

    # return the new string
    lw      $v0,16($sp)
    lw      $ra,28($sp)
    add     $sp,$sp,32
    jr      $ra

    .include  "./util.s"
