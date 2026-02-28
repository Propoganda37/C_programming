#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 -g -c *.c
gcc -o app.exe *.o
