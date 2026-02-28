#!/bin/bash

cd "$(dirname "$0")" || exit 2

clang -std=c99 -Wall -Werror -Wno-unused-result -Wpedantic -Wextra -fsanitize=address -Iinc ./src/*.c -o app.exe
