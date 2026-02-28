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
int **allocate_matrix(size_t n, size_t m)
{
    int **matrix = calloc(n, sizeof(int*));
    if (!matrix)
    {
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(int));
        if (!matrix[i])
        {
            free_matrix(matrix, n);
            return NULL;
        }
    }
    return matrix;
}

// Функция освобождения памяти
void free_matrix(int **matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция чтения матрицы
int read_matrix(FILE *f, int **matrix, size_t n, size_t m)
{
    int rc;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            rc = fscanf(f, "%d", &matrix[i][j]);
            if (rc != 1)
            {
                return ERR_MATRIX;
            }
        }
    }
    return 0;
}

void print_matrix(FILE *f, int **matrix, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            fprintf(f, "%d ", matrix[i][j]);
        }
        fprintf(f, "\n");
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
        printf("В матрице не целое число\n");
        break;
    case ERR_SIZE:
        printf("Неверный размер матрицы\n");
        break;
    case ERR_NO_PAL:
        printf("В матрице нет палиндромов\n");
        break;
    default:
        printf("Возникла неизвестная ошибка\n");
        break;
    }
}