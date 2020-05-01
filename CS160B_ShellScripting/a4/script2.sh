#!/bin/bash
#
# Jesse E Rodarte
# 04/28/19
# CS 160B
# Parameters, I/O file descriptors, and redirection
# Part 2
#
# script2.sh
#
# This scripts reads the contents of the files created by
# script1. For each file and directory it outputs its name
# and size, using the stat command.
#
# There are 2 options that let you provide the name of
# files, otherwise it will search for the default names.
#
#########################################################

set -ue

die() {
        echo "killing"
        printf '%s\n' "$1" >&2
        exit 1
}

filename="files.txt"
dirname="dirs.txt"

if [ ! $# -eq 0 ] ; then
        echo "first arg is $1"
        dirname=$1
        if [ $# -gt 1 ] ; then
                echo "second arg is $2"
                filename=$2
        fi
fi

if [ ! -e "$dirname" ] ; then
        die "ERROR: $dirname does not exist"
fi
if [ ! -e "$filename" ] ; then
        die "ERROR: $filename does not exist"
fi

echo 
echo "Reading from directories file: "
while read -r line ; do
        stat --format="Name: %n, Size: %s" "$line"
done < "$dirname"

echo 
echo "Reading from files file: "
while read -r line ; do
        stat --format="Name: %n, Size: %s" "$line"
done < "$filename"

exit 0

