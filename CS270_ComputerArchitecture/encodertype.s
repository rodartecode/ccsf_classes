#
# encodertype.s: This program has variables for the
# fields of an R-type instruction (op, rs, rt, rd, shamt, funct)
# that the user sets for whatever R-type instrucion they want to
# encode. The main program them calls the function encodertype:
#
#    unsigned encodertype(unsigned opc, unsigned rs, unsigned rt,
#        unsigned rd, unsigned shamt, unsigned funct);
#
# which encodes the R-type instruction, returning the instruction.
#
# The main program then decodes the instruction and outputs the value of
# each field for checking.
#
# The function interface and main program are written for you! All you have
# to do is to fill in the missing code in the function to actually do
# the encoding, following the instructions. SEE THE END OF THIS FILE.
#
# This program should be run with the exception handler.
#
	.data 
# Alter these values for the instruction you want to encode.
# The default encoded one is for: srl $a0, $t9, 21
opc:    .word 48
rs:     .word 5
rt:     .word 9
rd:     .word 48
shamt:  .word 20
funct:  .word 3
opcstring: .asciiz "\nThe encoded opc is:"
rsstring: .asciiz "\nThe encoded rs is:"
rtstring: .asciiz "\nThe encoded rt is:"
rdstring: .asciiz "\nThe encoded rd is:"
shamtstring: .asciiz "\nThe encoded shamt is:"
functstring: .asciiz "\nThe encoded funct is:"

    .text
    .globl main
main:
    addiu   $sp,$sp,-28
    sw      $ra,24($sp)
    # prepare for the call to encodertype
    lw      $a0,opc
    lw      $a1,rs
    lw      $a2,rt
    lw      $a3,rd
    lw      $t0,shamt
    sw      $t0,16($sp)
    lw      $t0,funct
    sw      $t0,20($sp)
    jal     encodertype
    
    
    ##########################################################
    ##########################################################
    # result in $v0
    # move the result to $t9 since we need $v0 for syscalls
    move    $t9,$v0
    # print opc result
    la      $a0,opcstring
    li      $v0,4
    syscall
    
    srl     $a0,$t9,26
    li      $v0,1
    syscall
    
    # print rs result
    la      $a0,rsstring
    li      $v0,4
    syscall
    
    srl     $a0,$t9,21
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    
    # print rt result
    la      $a0,rtstring
    li      $v0,4
    syscall
    srl     $a0,$t9,16
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print rd result
    la      $a0,rdstring
    li      $v0,4
    syscall
    srl     $a0,$t9,11
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall

    # print shamt result
    la      $a0,shamtstring
    li      $v0,4
    syscall
    srl     $a0,$t9,6
    andi    $a0,$a0,0x1f
    li      $v0,1
    syscall
    # print funct result
    la      $a0,functstring
    li      $v0,4
    syscall
    andi    $a0,$t9,0x3f
    li      $v0,1
    syscall

    # return from main
    lw      $ra,24($sp)
    addiu   $sp,$sp,28
    jr      $ra

    .globl encodertype
encodertype:
    lw      $t0,16($sp) #shamt
    lw      $t1,20($sp) #funct
#####################
#  INSERT YOUR CODE IN THE SPACE BELOW.
#  
#  You can assume that the following values are ALREADY
#  in the following registers:
#      - opc   is in $a0
#      - rs    is in $a1
#      - rt    is in $a2
#      - rd    is in $a3
#      - shamt is in $t0
#      - funct is in $t1
#
#  You should use your knowledge of logical operator instructions
#  and shift instructions to line up the six values with the
#  appropriate bit widths. Your final encoded instruction MUST
#  go in $v0.
#
#  You can use any t-registers you like, and you can modify the a-regs
#  if you like. DO NOT USE OTHER REGISTERS!
#####################
#    unsigned encodertype(unsigned opc, unsigned rs, unsigned rt,
#        unsigned rd, unsigned shamt, unsigned funct);
	# source reg	5
	# target reg	5
	# Destination	5
	# shift amt	5
	# function	6
	add	$v0, $v0, $a0
	sll	$v0, $v0, 5
	add	$v0, $v0, $a1
	sll	$v0, $v0, 5
	add	$v0, $v0, $a2
	sll	$v0, $v0, 5
	add	$v0, $v0, $a3
	sll	$v0, $v0, 5
	add	$v0, $v0, $t0
	sll	$v0, $v0, 6
	add	$v0, $v0, $t1
	


    # Ensure the result is in $v0!

    # This returns to main.
    jr      $ra
