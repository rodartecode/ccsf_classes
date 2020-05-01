#!/bin/bash
#
# Jesse E Rodarte
# 05/03/19
# CS 160B
# Miscellaneous Topics                            
#
# a6.sh
#
# This script demonstrates usage of variables and 
# constants. Also creates a text file with some text in
# it, and then uses the 'exec' command to redirect input
# from the file to stdin and uses the 'read' command in 
# a loop to accept input from the file.
#
#########################################################

echo "Creating variables"
v1="This is a variable"
v2="22"
declare -r c1="THIS IS CONSTANT"
declare -r c2="111"

echo "v1 is $v1"
echo "v2 is $v2"
echo "c1 is $c1"
echo "c2 is $c2"
echo

echo "Unsetting v1"
unset v1
echo "v1 is $v1"
echo

echo "Changing constant c1"
c1="oh no it changed"
echo "c1 is $c1"
echo

echo "Unsetting constant c2"
unset c2
echo "c2 is $c2"
echo


echo "Creating file with text"
echo "this is some text for a file" > textfile.txt
echo "some more text for the file omnom" >> textfile.txt
echo "File created with the text:"
cat textfile.txt

echo "Exec redirecting stdin from text file"
exec < textfile.txt
echo "Reading input in loop"
for (( i=0; i<2; i++ ))
do
        read -r aLine
        echo "Line was read: $aLine"
done
exec 0<textfile.txt
echo
echo "done."
echo
echo

exit 0

