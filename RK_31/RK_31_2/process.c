#include <stdlib.h>
#include "const.h"
#include "process.h"

int check(int x)
{
    int num = 0, copy = x;
    if (x < 0)
    {
        x *= -1;
    }
    while (x > 0)
    {
        num = num * 10 + x % 10;
        x /= 10;
    }
    if (num == copy)
    {
        return 1;
    }
    return 0;
}

int create_arr(int **matrix, size_t n, size_t m, int **arr, size_t *arr_n)
{
    int count = 0;
    for (size_t j = 0; j < m; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (check(matrix[i][j]))
            {
                count += 1;
            }
        }
    }
    if (count == 0)
    {
        return ERR_NO_PAL;
    }
    int *a = calloc(count, sizeof(int));
    if (a == NULL)
    {
        return ERR_ALLOC;
    }
    *arr = a;
    count = 0;
    for (size_t j = 0; j < m; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (check(matrix[i][j]))
            {
                *arr[count++] = matrix[i][j];
            }
        }
    }
    *arr_n = count;
    return 0;
}

void sort(int arr[], size_t n)
{
    int min, tmp;
    size_t min_i;
    for (size_t i = 0; i < n; i++)
    {
        min = arr[i];
        min_i = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_i = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = tmp;
    }
}

void return_elem(int **matrix, size_t n, size_t m, int arr[])
{
    int count = 0;
    for (size_t j = 0; j < m; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (check(matrix[i][j]))
            {
                matrix[i][j] = arr[count++];
            }
        }
    }
}