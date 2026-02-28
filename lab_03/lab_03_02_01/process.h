#ifndef _PROCESS_H__

#define _PROCESS_H__

#include "const.h"

int sum_digits(int n);
void find_elem(int matrix[][M], size_t n, size_t m, size_t *p, size_t *q);
void delete_column(int matrix[][M], size_t n, size_t m, size_t num);
void delete_row(int matrix[][M], size_t n, size_t m, size_t num);

#endif
