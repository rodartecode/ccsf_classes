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
min:        .word   1
max:        .word   10
msgguess:   .asciiz "Make a guess.\n"
msgnewline: .asciiz "\n"
	.text
	.globl main
main:
	# Make space for arguments and saved return address
	subi  $sp, $sp, 20
	sw    $ra,16($sp)

	# Get the guess
	la    $a0, msgguess
    lw    $a1, min
    lw    $a2, max
    jal   GetGuess
    
    # Print the guess
    move  $a0, $v0
    jal   PrintInteger
    
    # Print a newline character
    la    $a0, msgnewline
    jal   PrintString
    
    # Return
    lw    $ra, 16($sp)
    addi  $sp, $sp, 20
    jr    $ra

################################
# GetGuess
################################

    .data
invalid:    .asciiz "Not a valid hexadecimal number.\n"
badrange:   .asciiz "Guess not in range.\n"
    .text
    .globl  GetGuess
# 
# C code:
#
# int GetGuess(char * question, int min, int max)
# {
#     // Local variables
#     int theguess;      // Store this on the stack
#     int bytes_read;    // You can just keep this one in a register
#     int status;        // This can also be kept in a register
#     char buffer[16];   // This is 16 contiguous bytes on the stack
#
#     // Loop
#     while (true)
#     {
#         // Print prompt, get string (NOTE: You must pass the
#         // address of the beginning of the character array
#         // buffer as the second argument!)
#         bytes_read = InputConsoleString(question, buffer, 16);
#         if (bytes_read == 0) return -1;
#
#         // Ok, we successfully got a string. Now, give it
#         // to axtoi, which, if successful, will put the
#         // int equivalent in theguess. 
#         //
#         // Here, you must pass the address of theguess as
#         // the first argument, and the address of the
#         // beginning of buffer as the second argument.
#         status = axtoi(&theguess, buffer);
#         if (status != 1)
#         {
#             PrintString(invalid);  // invalid is a global
#             continue;
#         }
#
#         // Now we know we got a valid hexadecimal number, and the
#         // int equivalent is in theguess. Check it against min and
#         // max to make sure it's in the right range.
#         if (theguess < min || theguess > max)
#         {
#             PrintString(badrange); // badrange is a global
#             continue;
#         }
#
#         return theguess;
#     }
# }
#     
#
GetGuess:
    # stack frame must contain $ra (4 bytes)
    # plus room for theguess (int) (4 bytes)
    # plus room for a 16-byte string (16)
    # plus room for arguments (16)
    # total: 40 bytes
    #  16 byte buffer is at 16($sp)
    #  theguess is at 32($sp)
    #  ra is at 36($sp)
    #  $a0 = string
    #  $a1 = min
    #  $a2 = max
	#######################
	# YOUR CODE HERE      #
	#######################
	
	# Prologue ###########################################
	addiu	$sp, $sp, -40		# Stack Pointer
	
	move	$t8, $a1		# save min and max 
	move	$t9, $a2 		# arguments
	
	la	$t5, msgguess		# save string
	la	$t6, invalid		# invalid string
	la	$t7, badrange		# out of range string
	sw	$ra, 36($sp)		# saved ra value
	# End Prologue ########################################
	
	
	
	# While loop ##########################################
While:
	li	$t0, 0			# initialize bytesRead variable
	la	$a0, ($t5)		# load address of guess string
	li	$v0, 4	
	syscall				# print guess message
	
	la	$a0, 16($sp)		# address to save string
	li	$a1, 16			# length of string
	li	$v0, 8			# read string sys-code
	syscall
	lb	$t4, ($a0)		# grab first char

	# Count bytes loop ####################################
For:
	beq	$t4, 10, EndFor		# byte is empty, end loop
	bge	$t0, 16, EndFor		# read 16 bytes, end loop
	
	addi	$t0, $t0, 1		# increment byte count
	addi	$a0, $a0, 1		# increment address
	lb	$t4, ($a0)		# new byte

	b	For
EndFor:
	# Count bytes end #####################################
	
	
	beqz	$t0, Zero		# if zero, return -1
	bne	$t0, 10, EndIfZero	# if newline, return -1
Zero:
	li	$v0, -1,
	b	EndWhile
EndIfZero:				# otherwise continure

	# axtoi call ##########################################
	la	$a0, 32($sp)
	la	$a1, 16($sp)
	jal	axtoi
	# end axtoi ###########################################

	beq	$v0, 1, EndIfStatus
	la	$a0, ($t6)		# load address of invalid string
	li	$v0, 4
	syscall
	b	Continue		# number was invalid, loop again
EndIfStatus:				# number was valid, continue
	
	lw	$t1, 32($sp)		# load the number
	blt	$t1, $t8, IfRange	# continue if within bounds
	ble	$t1, $t9, EndIfRange
	
IfRange:				# out of range number
	la	$a0, ($t7)		# address of out of range string
	li	$v0, 4
	syscall					
	b	Continue		# number out of range, loop again
EndIfRange:				# number is in range, continue

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
    
    .include  "./util.s"
