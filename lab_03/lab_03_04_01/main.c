/*
Программа меняет местами элементы матрицы
*/
#include <stdio.h>
#include "inout.h"
#include "process.h"

int main(void)
{
    // Ввод
    printf("Введите количество строк в матрице: ");
    size_t n;
    int rcn = scanf("%zu", &n);
    printf("Введите количество столбцов в матрице: ");
    size_t m;
    int rcm = scanf("%zu", &m);
    if (rcn != 1 || n < 1 || n > 10 || rcm != 1 || m < 1 || m > 10)
    {
        printf("Нужно ввести целое число от одного до десяти\n");
        return 1;
    }
    if (n != m)
    {
        printf("Матрица должна быть квадратной\n");
        return 2;
    }
    int matrix[N][M] = { 0 };
    printf("Введите элементы матрицы: \n");
    if (create_matrix(matrix, n, m) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    // Перестановка элементов
    swap(matrix, n, m);
    // Вывод матрицы
    printf("Полученная матрица:\n");
    print_matrix(matrix, n, m);
}
