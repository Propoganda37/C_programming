#!/bin/bash

cd "$(dirname "$0")" || exit 2

clang -std=c99 -Wall -Werror -Wpedantic -Wextra -fsanitize=undefined inout.c process.c main.c -o app.exe
