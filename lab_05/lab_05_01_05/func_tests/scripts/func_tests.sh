#!/bin/bash

cd "$(dirname "$0")" || exit 100

# Проверяем наличие исполняемого файла
if [ ! -f ../../app.exe ]; then
    echo "Create app.exe"
    exit 1
fi

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
    	echo "$file_in"" Failed"
    fi
elif [ "$result" == 2 ]; then
    if [ "$1" == "-v" ]; then
    	echo "$file_in"" Wrong return code"
    fi
fi
(( i++ ))
if [ "$i" -lt 10 ]; then
    file_in="../data/pos_0""$i""_in.txt"
    file_out="../data/pos_0""$i""_out.txt"
else
    file_in="../data/pos_""$i""_in.txt"
    file_out="../data/pos_""$i""_out.txt"
fi
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
    	echo "$file_in"" Wrong return code"
    fi
fi
(( j++ ))
if [ "$j" -lt 10 ]; then
    file_in="../data/neg_0""$j""_in.txt"
else
    file_in="../data/neg_""$j""_in.txt"
fi
done

# Вывод результатов тестирования
echo "$(( i - wrong_pos_tests - 1 )) out of $(( i - 1 )) positive tests passed"
echo "$(( j - wrong_neg_tests - 1 )) out of $(( j - 1 )) negative tests passed"
exit $(( wrong_pos_tests + wrong_neg_tests ))
