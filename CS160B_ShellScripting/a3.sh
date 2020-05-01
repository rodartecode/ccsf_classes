#!/bin/bash
#
# BY: JESSE RODARTE
# DATE: 04/11/19
# CLASS: CS160B
# ASSIGNMENT 3: FLOW CONTROL, LOOPS AND DOCUMENTATION
#
# DESCRIPTION:
# Small homework script that completes all the neccessary tasks. Including if
# statements, switch cases, for, until, and while loops.
#
###############################################################################
echo "Searching for a file"
if [ -e a2.sh ] ; then
        echo "File found!"
        stat -c "%n %s" a2.sh
fi
echo
echo "Searching for a directory"
if [ -d aTestDir ] ; then
        echo "Directory found!"        
else
        echo "Directory not found"
        echo "Creating directory"
        mkdir aTestDir
fi
echo
echo "Testing input"
echo "Enter a number"
read input
if [ "$input" -lt "10" ] ; then
        echo "Less than 10"
elif [ "$input" -lt "100" ] && [ "$input" -gt "50" ] ; then
        echo "Ok bigger number"
elif [ "$input" -gt "500" ] ; then
        echo "Wow thats a big 'un!!"
else
        echo "I don't like your tone..."
fi
echo
echo "Let's try again"
echo "Enter a number"
read input
case $input in
        [0-9] ) echo "Less than 10"
                ;;
        5[1-9]|[6-9][0-9] ) echo "Ok bigger number"
                ;;
        [1-4][0-9]|50|[1-4][0-9][0-9]|500 ) echo "I really don't like your tone."
                ;;
        * ) echo "Woo baby, its L O R G E"
                ;;
esac
echo
echo "Ok let's take this one for a loop"
for file in ?*
do
        if [ -f "$file" ] ; then
                echo "$file is a File"
        elif [ -d "$file" ] ; then
                echo "$file is a Directory"
        fi
done
echo
echo "Let's go again!"
for (( i=7; i<=37; i+=3))
do
        echo "Iterator is at $i"
done
echo
echo "Ok let's play a game"
number=0
until [ $number -gt 10 ] ; do
        echo "I need you to give me a number"
        read number
        if [ "$number" -le 10 ] ; then
                echo "NOPE. Not good enough"
        fi
done
echo "Oh yeah. That's a good number"
echo
echo "Ok, one more game and we're done"
answer="no"
while [ "$answer" != "yes" ] ; do
        echo "Ok, are you ready to finish?"
        read answer
        if [ "$answer" != "yes" ] ; then
                echo "Hm, I'm really not sure about that."
        fi
done
echo "Ok all done!"
exit 0
