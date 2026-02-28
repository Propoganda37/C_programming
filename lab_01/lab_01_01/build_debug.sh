#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -O0 -g -c main.c
gcc -o app.exe main.c
