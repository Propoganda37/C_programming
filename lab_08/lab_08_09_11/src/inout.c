// Функции ввода и вывода

#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "inout.h"

// Функция чтения размеров матрицы из файла
int read_size(FILE *f, size_t *n, size_t *m)
{
    int tmp1, tmp2;
    int rc = fscanf(f, "%d%d", &tmp1, &tmp2);
    if (rc != 2 || tmp1 <= 0 || tmp2 <= 0)
    {
        return ERR_SIZE;
    }
    *n = tmp1;
    *m = tmp2;
    return 0;
}

// Функция выделения памяти для матрицы
double **allocate_matrix(size_t n, size_t m)
{
    double **matrix = calloc(n, sizeof(double*));
    if (!matrix)
    {
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(double));
        if (!matrix[i])
        {
            free_matrix(matrix, n);
            return NULL;
        }
    }
    return matrix;
}

// Функция освобождения памяти
void free_matrix(double **matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция чтения матрицы
int read_matrix(FILE *f, size_t n, size_t m, double **matrix)
{
    int rc;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            rc = fscanf(f, "%lf", &matrix[i][j]);
            if (rc != 1)
            {
                return ERR_MATRIX;
            }
        }
    }
    return 0;
}

// Функция вывода матрицы в файл
void print_matrix(FILE *f, size_t n, size_t m, double **matrix)
{
    fprintf(f, "%zu %zu\n", n, m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            fprintf(f, "%f ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }
}

// Функция вывода столбца решений в файл
void print_solution(FILE *f, double arr[], size_t n)
{
    fprintf(f, "%zu 1\n", n);
    for (size_t i = 0; i < n; i++)
    {
        fprintf(f, "%f\n", arr[i]);
    }
}

void print_error(int rc)
{
    switch (rc)
    {
        case ERR_ALLOC:
            printf("Не удалось выделить память\n");
            break;
        case ERR_ARGS:
            printf("Неверные аргументы командной строки\n");
            break;
        case ERR_FILE:
            printf("Возникла ошибка при открытии файла\n");
            break;
        case ERR_MATRIX:
            printf("В матрице не вещественное число\n");
            break;
        case ERR_SIZE:
            printf("Неверный размер матрицы\n");
            break;
        case ERR_ADD:
            printf("Разный размер матриц\n");
            break;
        case ERR_MULT:
            printf("Неверные размеры матриц для умножения\n");
            break;
        case ERR_SLAE_NO_SOL:
            printf("СЛАУ не имеет решений или имеет бесконечно много решений\n");
            break;
        case ERR_SLAE_SIZE:
            printf("Неверный размер матрицы для СЛАУ\n");
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
            break;
    }
}
