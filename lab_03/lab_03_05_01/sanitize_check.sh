#!/bin/bash

cd "$(dirname "$0")" || exit 1

echo "Тесты с адрес санитайзером"
./build_debug_asan.sh
./sanitize_func_tests.sh
echo "Тесты с санитайзером памяти"
./build_debug_msan.sh
./sanitize_func_tests.sh
echo "Тесты с санитайзером неопредлённого поведения"
./build_debug_ubsan.sh
./sanitize_func_tests.sh
