#ifndef _PROCESS_H__

#define _PROCESS_H__

#include "const.h"

int find_max(int matrix[][M], size_t n, size_t m);
void create_mas(int matrix[][M], size_t n, size_t m, int mas[]);
void change_rows(int matrix[][M], size_t m, size_t num1, size_t num2);
void sort(int matrix[][M], size_t n, size_t m, int mas[]);

#endif
