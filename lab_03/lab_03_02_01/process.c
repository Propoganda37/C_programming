#include <stddef.h>
#include <stdlib.h>
#include "process.h"

// Функция для подсчёта суммы цифр
int sum_digits(int n)
{
    n = abs(n);
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}


// Функция для нахождения элемента с минимальной суммой цифр
void find_elem(int matrix[][M], size_t n, size_t m, size_t *p, size_t *q)
{
    int min = sum_digits(matrix[0][0]);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            int k = sum_digits(matrix[i][j]);
            if (k < min)
            {
                min = k;
                *p = i;
                *q = j;
            }
        }
    }
}

// Функция для удаления столбца
void delete_column(int matrix[][M], size_t n, size_t m, size_t num)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = num + 1; j < m; j++)
        {
            matrix[i][j - 1] = matrix[i][j];
        }
    }
}

// Функция для удаления строки
void delete_row(int matrix[][M], size_t n, size_t m, size_t num)
{
    for (size_t j = 0; j < m; j++)
    {
        for (size_t i = num + 1; i < n; i++)
        {
            matrix[i - 1][j] = matrix[i][j];
        }
    }
}
