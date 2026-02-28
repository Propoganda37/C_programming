// Функции ввода вывода матрицы

#include <stdio.h>
#include <stddef.h>
#include "inout.h"

// Функция заполнения матрицы
int create_matrix(int matrix[][M], size_t n, size_t m)
{
    // Ввод элементов
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            int rc = scanf("%d", &matrix[i][j]);
            if (rc != 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Вывод массива
void print_mas(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
