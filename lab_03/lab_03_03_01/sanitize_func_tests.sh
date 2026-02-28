#!/bin/bash

cd "$(dirname "$0")" || exit 1

# Тестирование положительных тестов
i=1
file_in="func_tests/data/pos_0""$i""_in.txt"

while [ -f "$file_in" ]
do
echo "Позитивный тест $i"
./app.exe < "$file_in" > out.txt
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/pos_0""$i""_in.txt"
else
    file_in="func_tests/data/pos_""$i""_in.txt"
fi
done

# Тестирование отрицательных тестов
i=1
file_in="func_tests/data/neg_0""$i""_in.txt"

while [ -f "$file_in" ]
do
echo "Негативный тест $i"
./app.exe < "$file_in" > out.txt
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="func_tests/data/neg_0""$i""_in.txt"
else
    file_in="func_tests/data/neg_""$i""_in.txt"
fi
done
