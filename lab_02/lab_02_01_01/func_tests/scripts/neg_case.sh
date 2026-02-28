#!/bin/bash

cd "$(dirname "$0")" || exit 3

# Проверяем обязательные аргументы на наличие
if [ "$#" -lt 1 ]; then
    exit 2
fi

# Проверяем, являются ли файлы существующими файлами
if [ ! -f "$1" ]; then
    exit 2
fi

# Создаём исполняемый файл
../../build_release.sh main.c
cd "$(dirname "$0")" || exit 3

# Запускаем исполняемый файл и перенаправляем ввод и вывод
../../app.exe < "$1" > out.txt
result=$?

# Проверяем код возврата программы
if [ "$result" != 0 ]; then
    exit 0
else
    exit 1
fi
