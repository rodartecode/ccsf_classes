##################
# mymul function #
##################

# void checkregs(void); // contained in the main section
#
# int mymul(int left, int right) {
#    int retval;
#    // the function checkregs must be called here
#    // it ensures you are following the calling convention.
#    checkregs();
#    // here is the code for mymul that you must write
#    if (left == 1) retval = right;
#    else retval = (right + mymul(left - 1, right));
#    return(retval);
#}

    .globl mymul
mymul:  
    # put your entry code here
	addiu	$sp, $sp, -24
	sw		$ra, 24($sp)
	sw		$a0, 20($sp)
	sw		$a1, 16($sp)
    # you must call the function checkregs 
    jal     checkregs
    # finish mymul here
    
   lw		$t0, 20($sp)
   lw		$t1, 16($sp)
   
	bne	$t0, 1, else
	move	$v0, $t1
	b 		endIf
else:
	addi	$a0, $t0, -1
	move	$a1, $t1
	jal	mymul
	add	$v0, $t1, $v0
endIf:
	lw 	$ra, 24($sp)
	addiu	$sp, $sp, 24
    # and eventually return
    jr      $ra


################
# main section #
################

#
#  A partial implementation of the mymul program.
#  The user enters a multiplier and multiplicand. The
#  program computes multiplier * multiplicand using 
#  the recursive function mymul implemented above.

# /* product = multiplier * multiplicand */
#
# the function int mymul(int left, int right); is supplied by the user
# the support functions and main program follow:
    .data
banner:  .asciiz "Welcome to multiply. Enter the integers to multiply together.\n"
multiplier_prompt:  .asciiz "Enter the multiplier (first number): "
multiplicand_prompt:  .asciiz "Enter the multiplicand (second number): " 
result_banner:  .asciiz "Result="

    .text
    .globl main
# main() {
main:
    # main needs standard argument stack space, to save $ra 
    # and it needs three words of stack space for 
    # multiplier, multiplicand and product
    addiu   $sp,$sp,-32
    sw      $ra,28($sp)
    # 24($sp) is product
    # 20($sp) is multiplicand
    # 16($sp) is multiplier
    #    puts("Welcome to multiply. Enter the integers to multiply together");
    la      $a0,banner
    jal     PrintString
    #
    #    multiplier = get_int("Enter the multiplier (first number):");
    la      $a0,multiplier_prompt
    jal     get_int
    sw      $v0,16($sp)

    #    multiplicand = get_int("Enter the multiplicand (second number):");
    la      $a0,multiplicand_prompt
    jal     get_int
    sw      $v0,20($sp)

    #    product=mymul(multiplier,multiplicand);
    lw      $a0,16($sp)
    lw      $a1,20($sp)
    jal     mymul
    sw      $v0,24($sp)

    #    printf("Result=%d\n",product);
    la      $a0,result_banner
	jal     PrintString

    lw      $a0,24($sp)
    jal     PrintInteger

    lw      $ra,28($sp)
    addiu   $sp,$sp,32
    jr      $ra
#}

    .data
notpositive:  .asciiz "You must enter a positive integer.\n"
    .text
.globl get_int
get_int:
    # stack frame needed 
    addiu   $sp,$sp,-20
    # one temp space needed for integer result from InputConsoleInt
    # at 16($sp)
    sw      $ra,16($sp)
    # $a0 must be homed!
    # home $a0
    sw      $a0,20($sp)
Lloop:
    # move original a0 (prompt) back from home location
    # (in case this isn't the first time around the loop)
    lw      $a0,20($sp)
	jal     PrintString

    jal     InputConsoleInt
    # if the number was interpreted as a positive integer, we're done
    bgt     $v0,$zero,Lret1

    # if not, complain about the integer and try again
Lbadint:

    # output a message that the integer must be positive
    la      $a0,notpositive
    jal     PrintString

    # get another integer
    b       Lloop

Lret1:

    # result is in $v0 already.
    # just unwind the stack and return
    lw      $ra,16($sp)
    addiu   $sp,$sp,20
    jr      $ra


    .globl checkregs
checkregs:    
    # this function just destroys all volatile registers
    # and writes over its argument area
    li      $t0,-1
    move    $t1,$t0
    move    $t2,$t0
    move    $t3,$t0
    move    $t4,$t0
    move    $t5,$t0
    move    $t6,$t0
    move    $t7,$t0
    move    $t8,$t0
    move    $t9,$t0
    move    $a0,$t0
    move    $a1,$t0
    move    $a2,$t0
    move    $a3,$t0
    move    $v0,$t0
    move    $v1,$t0
    sw      $t0,0($sp)
    sw      $t0,4($sp)
    sw      $t0,8($sp)
    sw      $t0,12($sp)
    jr      $ra

.include "./util.s"

