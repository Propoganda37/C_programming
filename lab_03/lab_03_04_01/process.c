#include <stddef.h>
#include <stdlib.h>
#include "process.h"

// Функция для обмена строк
void swap(int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n / 2 + n % 2; i++)
    {
        for (size_t j = i; j < m - i; j++)
        {
            int el = matrix[i][j];
            matrix[i][j] = matrix[n - i - 1][j];
            matrix[n - i - 1][j] = el;
        }
    }
}
