#!/bin/bash

cd "$(dirname "$0")" || exit 2

if [ "$#" != 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -o app.exe "$1"
