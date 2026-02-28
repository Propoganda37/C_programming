#!/bin/bash

cd "$(dirname "$0")" || exit 1

gcc -std=c99 -Wall -Werror -fprofile-arcs -ftest-coverage -dumpbase '' -Iinc ./src/*.c -o app.exe

