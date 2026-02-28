#!/bin/bash

cd "$(dirname "$0")" || exit 2

gcc -std=c99 -Wall -Werror -Wvla -fprofile-arcs -ftest-coverage -o main.exe main.c -lm
