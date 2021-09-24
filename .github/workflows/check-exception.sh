#!/bin/bash

#RED="\e[41m"
#GREEN="\e[42m"
#BOLD="\e[1m"
#DEFAULT="\e[0m"

FILES="${@:2}"
failed=0

function check()
{
    if [ "$1" != 0 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "FOUND" $DEFAULT
    fi
}

function positive_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    egrep -s "$2" $FILES
    check $? $1
}

echo -e $BOLD "Performing checks" $DEFAULT

positive_lookup "should have InvalidGear that inherits from logic_error" "(class|struct)\s+InvalidGear\s*:\s*(public)?\s*(std::)?logic_error"
positive_lookup "should throw InvalidGear" "throw\s+InvalidGear"
# positive_lookup "should catch InvalidGear" "catch.*InvalidGear"

echo -e "==="

if [ $failed == 0 ]; then
    echo -e 💚💚💚 $GREEN "ALL CHECKS PASSED" 💚💚💚 $DEFAULT
else
    echo -e ❗️❗️❗️ $RED $failed "CHECKS FAILED" ❗️❗️❗️ $DEFAULT
fi

exit $failed