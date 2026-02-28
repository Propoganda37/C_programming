#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c inout.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -c process.c
gcc -o app.exe inout.o process.o main.o
