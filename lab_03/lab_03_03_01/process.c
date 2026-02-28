#include <stddef.h>
#include <stdlib.h>
#include "process.h"

// Функция для нахождения максимального элемента строки матрицы
int find_max(int matrix[][M], size_t n, size_t m)
{
    int max = matrix[n][0];
    for (size_t j = 1; j < m; j++)
    {
        if (max < matrix[n][j])
        {
            max = matrix[n][j];
        }
    }
    return max;
}

// Функция для заполнения массива максимумов
void create_mas(int matrix[][M], size_t n, size_t m, int mas[])
{
    for (size_t i = 0; i < n; i++)
    {
        mas[i] = find_max(matrix, i, m);
    }
}

// Функция для перестановки строк
void change_rows(int matrix[][M], size_t m, size_t num1, size_t num2)
{
    int el;
    for (size_t j = 0; j < m; j++)
    {
        el = matrix[num1][j];
        matrix[num1][j] = matrix[num2][j];
        matrix[num2][j] = el;
    }
}

// Функция для сортировки матрицы (выбором)
void sort(int matrix[][M], size_t n, size_t m, int mas[])
{
    size_t max_ind;
    for (size_t i = 0; i < n; i++)
    {
        max_ind = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (mas[j] > mas[max_ind])
            {
                max_ind = j;
            }
        }
        int el = mas[i];
        mas[i] = mas[max_ind];
        mas[max_ind] = el;
        change_rows(matrix, m, i, max_ind);
    }
}
