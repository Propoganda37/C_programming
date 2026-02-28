#!/bin/bash

cd "$(dirname "$0")" || exit 1

rm ./*.o
rm ./*.exe
rm ./*.txt
rm ./*.gcda
rm ./*.gcno
rm ./*.gcov
rm ./*.bin
rm ./func_tests/data/*.bin
