#!/bin/bash

cd "$(dirname "$0")" || exit 1

./build_coverage.sh

i=1
file_in="func_tests/data/pos_0""$i""_in.txt"
file_args="./func_tests/data/pos_0""$i""_args.txt"

while [ -f "$file_in" ] && [ -f "$file_args" ]
do
read -r args_line < "$file_args"
IFS=' ' read -r -a args <<< "$args_line"
./app.exe "${args[@]}" > out.txt
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/pos_0""$i""_in.txt"
    file_args="./func_tests/data/pos_0""$i""_args.txt"
else
    file_in="func_tests/data/pos_""$i""_in.txt"
    file_args="./func_tests/data/pos_""$i""_args.txt"
fi
done

i=1
file_in="func_tests/data/neg_0""$i""_in.txt"
file_args="./func_tests/data/neg_0""$i""_args.txt"

while [ -f "$file_in" ] && [ -f "$file_args" ]
do
read -r args_line < "$file_args"
IFS=' ' read -r -a args <<< "$args_line"
./app.exe "${args[@]}" > out.txt
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/neg_0""$i""_in.txt"
    file_args="./func_tests/data/neg_0""$i""_args.txt"
else
    file_in="func_tests/data/neg_""$i""_in.txt"
    file_args="./func_tests/data/neg_""$i""_args.txt"
fi
done

gcov *.c
