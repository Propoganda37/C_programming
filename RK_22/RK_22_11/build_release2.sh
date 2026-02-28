#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main2.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c process2.c
gcc -o app.exe process2.o main2.o
