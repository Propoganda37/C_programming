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
./app.exe import "$file_in" "${args[1]}"
./app.exe "${args[@]}" > out.txt
./app.exe export "${args[1]}" out.txt
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
if [ ! ${#args[@]} -eq 2 ] || [ "${args[0]}" != "s" ] && [ "${args[0]}" != "p" ]; then
    ./app.exe "${args[@]}" > out.txt
else
    ./app.exe import "$file_in" "${args[1]}"
    ./app.exe "${args[@]}" > out.txt
fi
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/neg_0""$i""_in.txt"
    file_args="./func_tests/data/neg_0""$i""_args.txt"
else
    file_in="func_tests/data/neg_""$i""_in.txt"
    file_args="./func_tests/data/neg_""$i""_args.txt"
fi
done

gcov main.c
gcov inout.c
gcov process.c
