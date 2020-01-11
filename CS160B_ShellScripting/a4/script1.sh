#!/bin/bash
#
# Jesse E Rodarte
# 04/27/19
# CS 160B
# Parameters, I/O file descriptors, and redirection
# Part 1
#
# script1.sh
# This script reads a directory and scans all of its content.
# For each item in the directory if its a file it write its
# name to a files which lists all the files. And if its a 
# directory it writes its name to a file of the names of the
# directories.
#
# It accepts 2 options, to change the names of the created
# files. It also accepts multiple arguments.
#
# If not directory is given the user is prompted to provide
# one.
#
#########################################################

filename="files.txt"
dirname="dirs.txt"

die() {
        echo "killing"
        printf '%s\n' "$1" >&2
        exit 1
}

scan() {
        if [ $# -eq 0 ] ; then
                die 'ERROR: "scan" requires non-empty option argument.'
        fi
        for file in "$1"/*
        do
                if [ -f "$file" ] ; then
                        echo "file found"
                        echo "$file" >> "$filename"
                elif [ -d "$file" ] ; then
                        echo "directory found"
                        echo "$file" >> "$dirname"
                fi
        done
}

while : ; do
        case $1 in
                -d)
                        if [ "$2" ]; then
                                echo "directory option used"
                                dirname=$2
                                shift
                        else
                                die 'ERROR: "-d" requires non-empty option argument.'
                        fi
                        ;;
                --files-list)
                        if [ "$2" ]; then
                                echo "files option used"
                                filename=$2
                                shift
                        else
                                die 'ERROR: "--files-list" requires non-empty option argument.'
                        fi
                        ;;
                *)
                        echo "done processing options"
                        break
        esac
        
        shift
done


if [ -e "$filename" ] ; then
        "files file already exists, overwriting"
        true > "$filename"
else
        echo "$filename does not exist, creating"
        touch "$filename"
fi
if [ -e "$dirname" ] ; then
        "dirs file already exists, overwriting"
        true > "$dirname"
else
        echo "$dirname does not exist, creating"
        touch "$dirname"
fi
        

if [ $# -eq 0 ] ; then
        echo "Enter a directory to scan: "
        read -r dir
        if [ -d "$dir" ] ; then
                scan "$dir"
        else
                die "ERROR: $dir is not a directory"
        fi
        
else
        for arg in "$@"
        do
                echo "arg is $arg"
                if [ -e "$arg" ] ; then
                        if [ -d "$arg" ] ; then
                                echo "scanning $arg"
                                scan "$arg"
                        else
                                echo "$arg is not a directory"
                        fi
                else
                        echo "$arg does not exist"
                fi
        done
fi

exit 0

