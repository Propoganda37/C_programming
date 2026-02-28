#include <stddef.h>
#include "process.h"

void create_mas(int mas[], int matrix[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m / 2 + m % 2; j++)
        {
            if (matrix[i][j] != matrix[i][m - j - 1])
            {
                mas[i] = 0;
                break;
            }
            else
            {
                mas[i] = 1;
            }
        }
    }
}
