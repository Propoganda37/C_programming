#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 -g -c main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 -g -c inout.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -O0 -g -c process.c
gcc -o app.exe inout.o process.o main.o
