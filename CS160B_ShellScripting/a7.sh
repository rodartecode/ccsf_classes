#!/bin/bash
# Jesse E Rodarte
# 05/03/19
# CS 160B
# Debugging and Function Libraries
#
# a7.sh
#
# This is the main shell script which executes and tests
# the functionality of a7_lib.sh.
#
# Use the '-d' option to set debug mode.
#
#########################################################

while :; do
    case $1 in
    -d)
        echo "debug option used"
        set -x
        shift
        ;;
    *)
        echo "done processing options"
        break
        ;;
    esac

    shift
done

set -euo pipefail
IFS=$'\n\t'

shopt -s expand_aliases
source ./a7_lib.sh

extension aFile.nnn
filename bbbaaa

echo
setval extension theVar aFile.aaa
echo "the variable has been assigned: $theVar"

echo
setthat filename
echo "that is now: $that"

echo
lla
echo
pall
echo
why
echo
whyyy

echo
answer="no"
while [ "$answer" != "y" ]; do
    echo "Type 'y' if you're ready quit."
    read answer
    if [ "$answer" != "y" ]; then
        echo "Gotcha, holding tight."
    fi
done
echo "Ok, finished."

exit 0
