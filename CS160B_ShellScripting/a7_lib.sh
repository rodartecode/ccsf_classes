#!/bin/bash
# Jesse E Rodarte
# 05/03/19
# CS 160B
# Debugging and Function Libraries
#
# a7_lib.sh
#
# This library defines the functions and aliases used in
# a7.sh
#
#########################################################

function cleanup() {
        echo "Alright I'm cleaning..."
        echo "Clean."
        echo
}

function extension() {
        if [ $# -eq 0 ]; then
                echo "ERROR: This function requires an argument"
                exit 1
        fi

        file="$1"
        index=$(expr index "$file" \.)

        if [ "$index" -eq 0 ]; then
                echo "ERROR: This file has no extension"
                exit 1
        fi

        ext=${file:index}
        echo "$ext"
}

function filename() {
        if [ $# -eq 0 ]; then
                echo "ERROR: This function requires an argument"
                exit 1
        fi

        file="$1"
        set +e
        index=$(expr index "$file" \.)
        set -e
        index=$((index - 1))
        if [ $index -lt 0 ]; then
                index=${#file}
        fi

        if [ "$index" -eq 0 ]; then
                echo "ERROR: This file has no extension"
                exit 1
        fi

        name=$(expr substr "$file" 1 "$index")

        echo "$name"
}

function setval() {
        if [ $# -lt 3 ]; then
                echo "ERROR: The function requires 3 parameters"
                exit 1
        fi

        func="$1"
        var="$2"
        param="$3"
        echo "the function: $func, " "the variable: $var, " "the parameter: $param"

        eval "$var"=$("$func" "$param")
        eval echo \$"$var"
}

alias setthat='_set_that() { setval "$1" that thattest.testext; }; _set_that'
alias lla='ls -la'
alias pall='lla ..'
alias why='mkdir y{1..50} ; ls ; rmdir y{1..50}'
alias whyyy='why ; why ; why'

trap "echo 'Takin the easy way out eh?' ; exit 2" SIGINT SIGTERM
trap 'cleanup' SIGQUIT EXIT
