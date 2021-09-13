#!/bin/bash

#RED="\e[41m"
#GREEN="\e[42m"
#BOLD="\e[1m"
#DEFAULT="\e[0m"

FILE=$1
failed=0

if [ ! -e "$FILE" ]; then
    echo -e "Given file does not exist - $FILE"
    exit 1
fi

function check()
{
    if [ "$1" != 0 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "FOUND" $DEFAULT
    fi
}

function negative_check()
{
    if [ "$1" == 0 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "NOT FOUND" $DEFAULT
    fi
}

function min_2_allowed_check()
{
    if [ "$1" -lt 2 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "OK" $DEFAULT
    fi
}

function positive_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    egrep "$2" "$FILE"
    check $? $1
}

function negative_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    egrep "$2" "$FILE"
    negative_check $? $1
}

function min_2_allowed_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    min_2_allowed_check `egrep "$2" "$FILE" -c` $1
}

function does_file_exist()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    if [[ -f "$1" ]]; then
        echo -e ✅ $GREEN "FILE EXISTS" $DEFAULT
    else
        echo -e ❌ $RED "FILE DOES NOT EXIST" $DEFAULT
        ((failed+=1))
    fi
}

echo -e $BOLD "Performing checks" $DEFAULT

positive_lookup "should have InvalidGear" "InvalidGear"
positive_lookup "should have std::logic_error" "logic_error"
positive_lookup "should have throw" "throw"
positive_lookup "should have catch" "catch"

echo -e "==="

if [ $failed == 0 ]; then
    echo -e 💚💚💚 $GREEN "ALL CHECKS PASSED" 💚💚💚 $DEFAULT
else
    echo -e ❗️❗️❗️ $RED $failed "CHECKS FAILED" ❗️❗️❗️ $DEFAULT
fi

exit $failed