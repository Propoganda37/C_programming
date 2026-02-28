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

# Запускаем исполняемый файл и перенаправляем вывод
./app.exe "${args[@]}" > out.txt
result=$?

# Проверяем код возврата программы
if [ "$result" != 0 ]; then
    exit 2
fi

# Запускаем компаратор с предполагаемым выходом и реальным
./func_tests/scripts/comparator.sh "$2" out.txt
result=$?

# Проверяем код возврата компаратора
if [ "$result" == 0 ]; then
    exit 0
else
    exit 1
fi
