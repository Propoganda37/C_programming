#ifndef _INOUT_H__

#define _INOUT_H__

#include <stdlib.h>
#include <stdio.h>

int read_size(FILE *f, size_t *n, size_t *m);
double **allocate_matrix(size_t n, size_t m);
void free_matrix(double **matrix, size_t n);
int read_matrix(FILE *f, size_t n, size_t m, double **matrix);
void print_matrix(FILE *f, size_t n, size_t m, double **matrix);
void print_solution(FILE *f, double arr[], size_t n);
void print_error(int rc);

#endif
