// Решение СЛАУ с выбором главного элемента по столбцу

#include <stdlib.h>
#include <math.h>
#include "slae.h"
#include "inout.h"
#include "const.h"

// Функция для нахождения главного элемента
size_t find_main_elem(double **matrix, size_t n, size_t j)
{
    size_t max_i = j;
    double max = matrix[j][j];
    for (size_t i = j + 1; i < n; i++)
    {
        if (fabs(max) < fabs(matrix[i][j]))
        {
            max = matrix[i][j];
            max_i = i;
        }
    }
    return max_i;
}

// Функция для решения СЛАУ
int solve(double **matrix, size_t n, size_t m, double **solution)
{
    if (n != m - 1)
    {
        return ERR_SLAE_SIZE;
    }
    size_t main_index;
    double *tmp;
    double eps = 0.000001;
    for (size_t i = 0; i < n; i++)
    {
        // Выбор главного элемента
        main_index = find_main_elem(matrix, n, i);
        tmp = matrix[main_index];
        matrix[main_index] = matrix[i];
        matrix[i] = tmp;
        // Нормализация строки
        double main_elem = matrix[i][i];
        if (fabs(main_elem) > eps)
        {
            for (size_t j = i; j < m; j++)
            {
                matrix[i][j] /= main_elem;
            }
        }
        // Вычитаем i-ую строку из строк под ней
        for (size_t j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i];
            for (size_t k = i; k < m; k++)
            {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }
    if (fabs(matrix[n - 1][n - 1]) < eps)
    {
        return ERR_SLAE_NO_SOL;
    }
    *solution = malloc(n * sizeof(double));
    // Двигаемся снизу вверх, получая решения
    for (int i = n - 1; i >= 0; i--) 
    {
        (*solution)[i] = matrix[i][n];
        for (size_t j = i + 1; j < n; j++) 
        {
            (*solution)[i] -= matrix[i][j] * (*solution)[j];
        }
    }
    return 0;
}
