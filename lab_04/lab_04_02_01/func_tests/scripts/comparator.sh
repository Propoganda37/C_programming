#!/bin/bash

# Проверяем обязательные аргументы на наличие
if [ $# -lt 2 ]; then
    exit 3
fi

# Проверяем, являются ли файлы существующими файлами
if [ ! -f "$1" ] || [ ! -f "$2" ]; then
    exit 3
fi

# Удаляем все символы до подстроки "Result: ", включая её
text1=$(sed -n "s/.*Result:[[:space:]]*//p" "$1")
text2=$(sed -n "s/.*Result:[[:space:]]*//p" "$2")
# Проверяем, есть ли в файлах подстрока "Result: "
if [ "$text1" == "" ] || [ "$text2" == "" ]; then
    exit 2
fi

if [ "$text1" == "$text2" ]; then
    exit 0
else
    exit 1
fi

