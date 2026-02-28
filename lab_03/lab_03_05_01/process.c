#include <stddef.h>
#include <stdlib.h>
#include "process.h"

// Функция для подсчёта суммы цифр
int sum_digits(int n)
{
    n = abs(n);
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Функция для заполнения массива
size_t create_mas(int matrix[][M], size_t n, size_t m, int mas[])
{
    size_t k = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (sum_digits(matrix[i][j]) > 10)
            {
                mas[k++] = matrix[i][j];
            }
        }
    }
    return k;
}

// Функция для сдвига элементов массива
void move(int mas[], size_t k)
{
    for (int i = 0; i < 3; i++)
    {
        int el = mas[0];
        for (size_t j = 1; j < k; j++)
        {
            mas[j - 1] = mas[j];
        }
        mas[k - 1] = el;
    }
}

// Функция для заполнения матрицы
void fill(int matrix[][M], size_t n, size_t m, int mas[])
{
    int k = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (sum_digits(matrix[i][j]) > 10)
            {
                matrix[i][j] = mas[k++];
            }
        }
    }
}
