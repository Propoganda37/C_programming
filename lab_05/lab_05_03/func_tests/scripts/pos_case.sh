#!/bin/bash

cd "$(dirname "$0")" || exit 4
cd ./../../

# Проверяем обязательные аргументы на наличие
if [ $# -lt 3 ]; then
    exit 3
fi

# Проверяем, являются ли файлы существующими файлами
if [ ! -f "$1" ] || [ ! -f "$2" ] || [ ! -f "$3" ]; then
    exit 3
fi

# Считываем аргументы командной строки
read -r args_line < "$3"
IFS=' ' read -r -a args <<< "$args_line"

# Получаем бинарный файл из текстового
./app.exe import "$1" "${args[1]}"
result=$?
    
if [ "$result" != 0 ]; then
    exit 2
fi

# Проверяем первый аргумент командной строки
if [ "${args[0]}" == "p" ]; then
    ./app.exe "${args[@]}" > out.txt
    result=$?
    
    if [ "$result" != 0 ]; then
        exit 2
    fi

    ./func_tests/scripts/comparator.sh "$2" out.txt
    result=$?

elif [ "${args[0]}" == "s" ]; then
    ./app.exe "${args[@]}"
    result=$?

    if [ "$result" != 0 ]; then
        exit 2
    fi

    ./app.exe export "${args[1]}" out.txt
    ./func_tests/scripts/comparator.sh "$2" out.txt
    result=$?
fi

# Проверяем код возврата компаратора
if [ "$result" == 0 ]; then
    exit 0
else
    exit 1
fi
