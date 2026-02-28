#include <stddef.h>
#include <stdlib.h>
#include "process.h"

// Функция для заполнения очередного контура
int fill_square(int matrix[][M], size_t n, size_t m, size_t num, int next)
{
    if (num == m - num - 1)
    {
        matrix[num][num] = next;
        return next;
    }
    for (size_t j = num; j < m - num - 1; j++)
    {
        matrix[num][j] = next++;
    }
    for (size_t i = num; i < n - num - 1; i++)
    {
        matrix[i][m - num - 1] = next++;
    }
    for (size_t j = m - num - 1; j > num; j--)
    {
        matrix[n - num - 1][j] = next++;
    }
    for (size_t i = n - num - 1; i > num; i--)
    {
        matrix[i][num] = next++;
    }
    return next;
}

// Функция для заполнения матрицы по спирали по часовой стрелке
void fill_matrix(int matrix[][M], size_t n, size_t m)
{
    int next = 1;
    for (size_t k = 0; k < n / 2 + n % 2; k++)
    {
        next = fill_square(matrix, n, m, k, next);
    }
}

