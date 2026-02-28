// Функции ввода вывода матрицы

#include <stdio.h>
#include <stddef.h>
#include "inout.h"

// Вывод матрицы
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
