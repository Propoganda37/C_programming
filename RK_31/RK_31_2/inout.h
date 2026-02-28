#ifndef _INOUT_H__

#define _INOUT_H__

int read_size(FILE *f, size_t *n, size_t *m);
int **allocate_matrix(size_t n, size_t m);
void free_matrix(int **matrix, size_t n);
int read_matrix(FILE *f, int **matrix, size_t n, size_t m);
void print_matrix(FILE *f, int **matrix, size_t n, size_t m);
void print_error(int rc);

#endif