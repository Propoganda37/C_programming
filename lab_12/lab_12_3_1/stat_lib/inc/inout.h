#ifndef _INOUT_H__

#define _INOUT_H__

int read_numbers(FILE *f, int **pb, int **pe);
void print_numbers(FILE *f, int *pb, int *pe);
void print_error(int rc);

#endif
