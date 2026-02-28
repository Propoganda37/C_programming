#!/bin/bash

cd "$(dirname "$0")" || exit 1

gcc -std=c99 -Wall -Werror -fprofile-arcs -ftest-coverage -dumpbase '' main.c inout.c process.c -o app.exe

