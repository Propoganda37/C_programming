#!/bin/bash

cd "$(dirname "$0")" || exit 3
cd ./../../

# Проверяем обязательные аргументы на наличие
if [ "$#" -lt 2 ]; then
    exit 2
fi

# Проверяем, являются ли файлы существующими файлами
if [ ! -f "$1" ] && [ ! -f "$2" ]; then
    exit 2
fi

# Считываем аргументы командной строки
read -r args_line < "$2"
IFS=' ' read -r -a args <<< "$args_line"

# Valgrind
if [ "$3" = "-val" ]; then
    valgrind --leak-check=yes ./app.exe "${args[@]}" > ./out/bin.txt 2>&1
    exit 1
fi

# Запускаем исполняемый файл и перенаправляем вывод
./app.exe "${args[@]}" > ./out/bin.txt
result=$?

# Проверяем код возврата программы
if [ "$result" != 0 ]; then
    exit 0
else
    exit 1
fi
