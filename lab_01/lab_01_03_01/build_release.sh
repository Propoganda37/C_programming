#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o app.exe main.c
