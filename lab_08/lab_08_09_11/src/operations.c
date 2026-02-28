// Функции сложения и умножения

#include <stdlib.h>
#include "operations.h"
#include "inout.h"
#include "const.h"

int adding(double **matrix1, size_t n1, size_t m1, double **matrix2, size_t n2, size_t m2, double **res_matrix)
{
    if (n1 != n2 || m1 != m2)
    {
        return ERR_ADD;
    }
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m1; j++)
        {
            res_matrix[i][j] = 0.0;
            res_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return 0;
}

int multiplication(double **matrix1, size_t n1, size_t m1, double **matrix2, size_t n2, size_t m2, double **res_matrix)
{
    if (m1 != n2)
    {
        return ERR_MULT;
    }
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            res_matrix[i][j] = 0.0;
            for (size_t k = 0; k < m1; k++)
            {
                res_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}
