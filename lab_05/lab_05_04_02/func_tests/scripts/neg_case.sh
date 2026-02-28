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

if [ ! ${#args[@]} -eq 3 ] || [ "${args[0]}" != "sb" ] && [ "${args[0]}" != "fb" ]; then
    ./app.exe "${args[@]}" > out.txt
    result=$?
else
    # Получаем бинарный файл из текстового
    ./app.exe import "$1" "${args[1]}"
    result=$?
    
    if [ "$result" != 0 ]; then
        exit 0
    fi

    # Запускаем исполняемый файл и перенаправляем вывод
    ./app.exe "${args[@]}" > out.txt
    result=$?
fi

# Проверяем код возврата программы
if [ "$result" != 0 ]; then
    exit 0
else
    exit 1
fi
