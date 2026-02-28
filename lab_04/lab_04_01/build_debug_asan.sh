#!/bin/bash

cd "$(dirname "$0")" || exit 2

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -fsanitize=address process.c main.c -o app.exe
