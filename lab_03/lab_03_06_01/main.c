/*
Программа создаёт массив из чисел матрицы, сумма цифр которых больше 10,
сдвигает его циклически на 3 влево и наполняет матрицу
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
    // Заполнение матрицы
    fill_matrix(matrix, n, m);
    // Вывод матрицы
    printf("Полученная матрица:\n");
    print_matrix(matrix, n, m);
}
