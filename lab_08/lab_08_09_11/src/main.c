#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inout.h"
#include "const.h"
#include "operations.h"
#include "slae.h"

int main(int argc, char **argv)
{
    size_t n1, m1;
    // Проверка аргументов командной строки
    if (!((argc == 4 && strcmp(argv[1], "o") == 0) || 
        (argc == 5 && (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0))))
    {
        print_error(ERR_ARGS);
        return ERR_ARGS;
    }
    // Открытие первого файла
    FILE *f1 = fopen(argv[2], "r");
    if (f1 == NULL)
    {
        print_error(ERR_FILE);
        return ERR_FILE;
    }
    // Чтение размеров первой матрицы
    int rc = read_size(f1, &n1, &m1);
    if (rc != 0)
    {
        print_error(rc);
        fclose(f1);
        return rc;
    }
    // Выделение памяти и чтение матрицы
    double **matrix1 = allocate_matrix(n1, m1);
    if (matrix1 == NULL)
    {
        print_error(ERR_ALLOC);
        fclose(f1);
        return ERR_ALLOC;
    }
    rc = read_matrix(f1, n1, m1, matrix1);
    if (rc != 0)
    {
        print_error(rc);
        free_matrix(matrix1, n1);
        fclose(f1);
        return rc;
    }
    if (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0)
    {
        // Открытие второго файла
        FILE *f2 = fopen(argv[3], "r");
        if (f2 == NULL)
        {
            print_error(ERR_FILE);
            free_matrix(matrix1, n1);
            fclose(f1);
            return ERR_FILE;
        }
        // Чтение второй матрицы
        size_t n2, m2;
        int rc = read_size(f2, &n2, &m2);
        if (rc != 0)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            fclose(f1);
            fclose(f2);
            return rc;
        }
        double **matrix2 = allocate_matrix(n2, m2);
        if (matrix2 == NULL)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            fclose(f1);
            fclose(f2);
            return ERR_ALLOC;
        }
        rc = read_matrix(f2, n2, m2, matrix2);
        if (rc != 0)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            free_matrix(matrix2, n2);
            fclose(f1);
            fclose(f2);
            return rc;
        }
        // Выделение памяти под результирующую матрицу
        double **res_matrix = allocate_matrix(n1, m2);
        if (res_matrix == NULL)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            free_matrix(matrix2, n2);
            fclose(f1);
            fclose(f2);
            return ERR_ALLOC;
        }
        // Сложение
        if (strcmp(argv[1], "a") == 0)
        {
            rc = adding(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
        }
        // Умножение
        else
        {
            rc = multiplication(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
        }
        if (rc != 0)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            free_matrix(matrix2, n2);
            free_matrix(res_matrix, n1);
            fclose(f1);
            fclose(f2);
            return rc;
        }
        FILE *f_out = fopen(argv[4], "w");
        if (f_out == NULL)
        {
            print_error(ERR_FILE);
            free_matrix(matrix1, n1);
            free_matrix(matrix2, n2);
            free_matrix(res_matrix, n1);
            fclose(f1);
            fclose(f2);
            return ERR_FILE;
        }
        print_matrix(f_out, n1, m2, res_matrix);
        free_matrix(matrix2, n2);
        free_matrix(res_matrix, n1);
        fclose(f2);
        fclose(f_out);
    }
    else
    {
        double *solution = NULL;
        rc = solve(matrix1, n1, m1, &solution);
        if (rc != 0)
        {
            print_error(rc);
            free_matrix(matrix1, n1);
            fclose(f1);
            return rc;
        }
        FILE *f_out = fopen(argv[3], "w");
        if (f_out == NULL)
        {
            print_error(ERR_FILE);
            free_matrix(matrix1, n1);
            free(solution);
            fclose(f1);
            return ERR_FILE;
        }
        print_solution(f_out, solution, n1);
        free(solution);
        fclose(f_out);
    }
    free_matrix(matrix1, n1);
    fclose(f1);
    return 0;
}
