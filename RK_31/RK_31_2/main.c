#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "inout.h"
#include "const.h"

int main(int argc, char **argv)
{
    size_t n, m, arr_n;
    if (argc != 3)
    {
        print_error(ERR_ARGS);
        return ERR_ARGS;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        print_error(ERR_FILE);
        return ERR_FILE;
    }
    int rc = read_size(f, &n, &m);
    printf("%zu %zu", n, m);
    if (rc != 0)
    {
        print_error(rc);
        return rc;
    }
    int **matrix = allocate_matrix(n, m);
    rc = read_matrix(f, matrix, n, m);
    if (rc != 0)
    {
        print_error(rc);
        return rc;
    }
    int *arr = NULL;
    rc = create_arr(matrix, n, m, &arr, &arr_n);
    if (rc != 0)
    {
        free_matrix(matrix, n);
        print_error(rc);
        return rc;
    }
    sort(arr, arr_n);
    return_elem(matrix, n, m, arr);
    FILE *f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        free_matrix(matrix, n);
        free(arr);
        print_error(ERR_FILE);
        return ERR_FILE;
    }
    print_matrix(f_out, matrix, n, m);
    free_matrix(matrix, n);
    free(arr);
    return 0;
}