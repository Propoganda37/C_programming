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
    int matrix[N][M] = { 0 };
    printf("Введите элементы матрицы: \n");
    if (create_matrix(matrix, n, m) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    // Получение массива чисел
    int mas[K] = { 0 };
    size_t k = create_mas(matrix, n, m, mas);
    if (k == 0)
    {
        printf("В матрице нет чисел с суммой цифр больше десяти\n");
        return 2;
    }
    // Сдвиг массива
    move(mas, k);
    // Заполнение матрицы
    fill(matrix, n, m, mas);
    // Вывод матрицы
    printf("Полученная матрица:\n");
    print_matrix(matrix, n, m);
}
