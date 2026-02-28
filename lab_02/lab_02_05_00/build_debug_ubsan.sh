#!/bin/bash

cd "$(dirname "$0")" || exit 2

clang -std=c99 -Wall -Werror -Wvla -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined main.c -o app.exe -lm
