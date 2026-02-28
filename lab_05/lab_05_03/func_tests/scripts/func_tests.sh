#!/bin/bash

cd "$(dirname "$0")" || exit 100
cd ./../../

# Проверяем наличие исполняемого файла
if [ ! -f ./app.exe ]; then
    echo "Create app.exe"
    exit 1
fi

# Тестирование положительных тестов
wrong_pos_tests=0
i=1
file_in="./func_tests/data/pos_0""$i""_in.txt"
file_out="./func_tests/data/pos_0""$i""_out.txt"
file_args="./func_tests/data/pos_0""$i""_args.txt"

while [ -f "$file_in" ] && [ -f "$file_out" ] && [ -f "$file_args" ]
do
./func_tests/scripts/pos_case.sh "$file_in" "$file_out" "$file_args"
result=$?
if [ "$result" == 1 ]; then
    (( wrong_pos_tests++ ))
    if [ "$1" == "-v" ]; then
    	echo "$file_in"" Failed"
    fi
elif [ "$result" == 2 ]; then
    if [ "$1" == "-v" ]; then
    	echo "$file_in"" Wrong return code"
    fi
fi
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="./func_tests/data/pos_0""$i""_in.txt"
    file_out="./func_tests/data/pos_0""$i""_out.txt"
    file_args="./func_tests/data/pos_0""$i""_args.txt"
else
    file_in="./func_tests/data/pos_""$i""_in.txt"
    file_out="./func_tests/data/pos_""$i""_out.txt"
    file_args="./func_tests/data/pos_""$i""_args.txt"
fi
done

# Тестирование отрицательных тестов
j=1
wrong_neg_tests=0
file_in="./func_tests/data/neg_0""$j""_in.txt"
file_args="./func_tests/data/neg_0""$j""_args.txt"

while [ -f "$file_in" ] && [ -f "$file_args" ]
do
./func_tests/scripts/neg_case.sh "$file_in" "$file_args"
result=$?
if [ "$result" == 1 ]; then
    (( wrong_neg_tests++ ))
    if [ "$1" == "-v" ]; then
    	echo "$file_in"" Wrong return code"
    fi
fi
(( j++ ))
if [ "$j" -lt 10 ]; then
    file_in="./func_tests/data/neg_0""$j""_in.txt"
    file_args="./func_tests/data/neg_0""$j""_args.txt"
else
    file_in="./func_tests/data/neg_""$j""_in.txt"
    file_args="./func_tests/data/neg_""$j""_args.txt"
fi
done

# Вывод результатов тестирования
echo "$(( i - wrong_pos_tests - 1 )) out of $(( i - 1 )) positive tests passed"
echo "$(( j - wrong_neg_tests - 1 )) out of $(( j - 1 )) negative tests passed"
exit $(( wrong_pos_tests + wrong_neg_tests ))
