#!/bin/bash
#
# Jesse E Rodarte
# 04/28/19
# CS 160B
# Parameters, I/O file descriptors, and redirection
# Part 3
#
# script3.sh
#
# This script calls and uses script1 and script2 using
# using options and arguments.
# 
# The user can provide a directory name to use as an 
# argument. Otherwise the script will use the current
# directory "."
#
#########################################################

set -ue

dirs=()
dirname="."
script1="./script1.sh"
script2="./script2.sh"

die() {
        echo "killing"
        printf '%s\n' "$1" >&2
        exit 1
}

if [ ! $# -eq 0 ] ; then
        echo "first arg is $1"
        dirname=$1
fi

if [ ! -d "$dirname" ] ; then
        die "ERROR: $dirname is not a valid directory path"
elif [ ! -e "$script1" ] || [ ! -e "$script2" ] ; then
        die "ERROR: Missing script!"
fi

for file in "$dirname"/*
do
        if [ -d "$file" ] ; then
                echo "directory found"
                dirs+=("$file")
        fi
done

echo
echo "Running script1"
eval '"$script1" -d dirs.dir "${dirs[@]}"' ; echo "Done"
echo

echo "Running script2"
eval '"$script2" dirs.dir' ; echo "Done"

exit 0

