#!/bin/bash

cd "$(dirname "$0")" || exit 1

# Тестирование положительных тестов
i=1
file_in="func_tests/data/pos_0""$i""_in.txt"
file_args="./func_tests/data/pos_0""$i""_args.txt"

while [ -f "$file_in" ] && [ -f "$file_args" ]
do
echo "Позитивный тест $i"
read -r args_line < "$file_args"
IFS=' ' read -r -a args <<< "$args_line"
./app.exe import "$file_in" "${args[1]}"
./app.exe "${args[@]}" > out.txt
if [ "${args[0]}" == "sb" ]; then
    ./app.exe export "${args[2]}" out.txt
fi
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/pos_0""$i""_in.txt"
    file_args="./func_tests/data/pos_0""$i""_args.txt"
else
    file_in="func_tests/data/pos_""$i""_in.txt"
    file_args="./func_tests/data/pos_""$i""_args.txt"
fi
done

# Тестирование отрицательных тестов
i=1
file_in="func_tests/data/neg_0""$i""_in.txt"
file_args="./func_tests/data/neg_0""$i""_args.txt"

while [ -f "$file_in" ]
do
echo "Негативный тест $i"
read -r args_line < "$file_args"
IFS=' ' read -r -a args <<< "$args_line"
if [ ! ${#args[@]} -eq 3 ] || [ "${args[0]}" != "sb" ] && [ "${args[0]}" != "fb" ]; then
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
    file_args="./func_tests/data/neg_0""$i""_args.txt"
fi
done
