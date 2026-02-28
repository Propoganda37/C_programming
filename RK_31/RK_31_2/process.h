#ifndef _PROCESS_H__

#define _PROCESS_H__

#include <stdlib.h>

int check(int x);
int create_arr(int **matrix, size_t n, size_t m, int **arr, size_t *arr_n);
void sort(int arr[], size_t n);
void return_elem(int **matrix, size_t n, size_t m, int arr[]);

#endif