/*
Программа по матрице получает одномерный массив, присваивая его 𝑘-
тому элементу значение 1, если k-ая строка матрицы симметрична, иначе 0
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
    int matrix[N][M] = { 0 };
    printf("Введите элементы матрицы: \n");
    if (create_matrix(matrix, n, m) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    int mas[N] = { 0 };
    // Получение и вывод массива
    create_mas(mas, matrix, n, m);
    printf("Полученный массив:\n");
    print_mas(mas, n);
}
