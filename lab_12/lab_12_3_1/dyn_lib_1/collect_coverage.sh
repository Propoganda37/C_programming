#!/bin/bash

cd "$(dirname "$0")" || exit 1

./build_coverage.sh

./func_tests/scripts/func_tests.sh > /dev/null

gcov ./src/*.c -o .
