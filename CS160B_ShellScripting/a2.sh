#!/bin/bash
#
# Jesse E Rodarte
# 04/07/19
# CS 160B
# Assignment 2: Basics, Variables, Substitution & Quoting
#
##########################################################
num1=1
num2=2
num3=3
num4=4

string1="this is a string"
string2='this is a string'
string3="this is $string1"
string4='this is $string1'
string5=$((4+3*2-1))
string6=$(($num1+$num2*$num3-$num4))
string7=$(echo a*)

echo "$string1"
echo
echo "$string2"
echo
echo "$string3"
echo
echo "$string4"
echo
echo "$string5"
echo
echo "$string6"
echo
echo "$string7"
