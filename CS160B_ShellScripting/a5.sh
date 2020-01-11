#!/bin/bash
#
# Jesse E Rodarte
# 04/29/19
# CS 160B
# Functions
#
# a5.sh
# 
# Uses 2 functions to scan a given directory, and then output a list that
# includes the name and size of all the files in that directory.
#
#########################################################

dir="."

files() {
        files=()
        if [ $# -gt 0 ] ; then
                dir="$1"
        fi
        
        for file in "$dir"/*
        do
                if [ -f "$file" ] ; then
                        echo "$file is a file"
                        dirs+=("$file")
                fi
        done
}

sizes() {
        echo
        echo "Reading file sizes"
        for file in "${files[@]}"
        do
                stat --format="Name: %n, Size: %s" "$file"
        done
}

if [ $# -gt 0 ] ; then
        echo "Searching: $1"
        files "$1"
else
        echo "No directory provided, searching current directory"
        files
fi

sizes

exit 0

