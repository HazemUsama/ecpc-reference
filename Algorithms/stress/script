#!/bin/bash

SCRIPT_DIR=$(dirname -- "${BASH_SOURCE[0]}")

g++ -std=c++17 "$SCRIPT_DIR"/Generator.cpp -o Generator 
g++ -std=c++17 "$SCRIPT_DIR"/Test.cpp -o Test 
g++ -std=c++17 "$SCRIPT_DIR"/Correct.cpp -o Correct 

max_tests=1000
diff_found=0

for i in $(seq 1 $max_tests); do
    ./Generator > input.txt
    ./Test < input.txt > Test_output.txt

    if ! diff -q Test_output.txt <(./Correct < input.txt); then
        diff_found=1
        break
    fi
done

if [ $diff_found -eq 1 ]; then
    echo ""
    echo "Test_Case #$i: Failed"
    echo "Input: "
    cat input.txt
    echo ""
    echo "Output: "
    cat Test_output.txt
    echo ""
    echo "Expected: "
    ./Correct < input.txt
    notify-send "Wrong Answer"
else
    notify-send "Accepted"
fi

rm Generator Test Correct *.txt
echo ""
