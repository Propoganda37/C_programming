#!/bin/bash

# Проверяем обязательные аргументы на наличие
if [ $# -lt 2 ]; then
    exit 3
fi

# Проверяем, являются ли файлы существующими файлами
if [ ! -f "$1" ] || [ ! -f "$2" ]; then
    exit 3
fi

diff "$1" "$2"
result=$?
if [ $result -eq 0 ]; then
    exit 0
else
    exit 1
fi

