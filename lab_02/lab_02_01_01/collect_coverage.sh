#!/bin/bash

cd "$(dirname "$0")" || exit 1

./build_coverage.sh

i=1
file_in="func_tests/data/pos_0""$i""_in.txt"

while [ -f "$file_in" ]
do
./main.exe < "$file_in" > out.txt
(( i++ ))
file_in="func_tests/data/pos_0""$i""_in.txt"
done

i=1
file_in="func_tests/data/neg_0""$i""_in.txt"

while [ -f "$file_in" ]
do
./main.exe < "$file_in" > out.txt
(( i++ ))
file_in="func_tests/data/neg_0""$i""_in.txt"
done

gcov main.c
