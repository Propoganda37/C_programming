#!/bin/bash

cd "$(dirname "$0")" || exit 100

# Тестирование положительных тестов
wrong_pos_tests=0
i=1
file_in="../data/pos_0""$i""_in.txt"
file_out="../data/pos_0""$i""_out.txt"

while [ -f "$file_in" ] && [ -f "$file_out" ]
do
./pos_case.sh "$file_in" "$file_out"
result=$?
if [ "$result" == 1 ]; then
    (( wrong_pos_tests++ ))
    if [ "$1" == "-v" ]; then
    	echo "pos_0""$i""_in.txt Failed"
    fi
elif [ "$result" == 2 ]; then
    if [ "$1" == "-v" ]; then
    	echo "pos_0""$i""_in.txt Wrong return code"
    fi
fi
(( i++ ))
file_in="../data/pos_0""$i""_in.txt"
file_out="../data/pos_0""$i""_out.txt"
done

# Тестирование отрицательных тестов
j=1
wrong_neg_tests=0
file_in="../data/neg_0""$j""_in.txt"

while [ -f "$file_in" ]
do
./neg_case.sh "$file_in"
result=$?
if [ "$result" == 1 ]; then
    (( wrong_neg_tests++ ))
    if [ "$1" == "-v" ]; then
    	echo "neg_0""$j""_in.txt Wrong return code"
    fi
fi
(( j++ ))
file_in="../data/neg_0""$j""_in.txt"
done

# Вывод результатов тестирования
echo "$(( i - wrong_pos_tests - 1 )) out of $(( i - 1 )) positive tests passed"
echo "$(( j - wrong_neg_tests - 1 )) out of $(( j - 1 )) negative tests passed"
exit $(( wrong_pos_tests + wrong_neg_tests ))
