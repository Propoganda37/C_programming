/*
Программа удаляет столбец и строку, на пересечении которых располагается
элемент с минимальной суммой цифр
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
    if (n == 1 || m == 1)
    {
        printf("Нельзя удалить всю матрицу\n");
        return 2;
    }
    size_t i = 0, j = 0;
    size_t *pi = &i, *pj = &j;
    // Нахождение элемента с минимальной суммой цифр
    find_elem(matrix, n, m, pi, pj);
    // Удаление столбца
    delete_column(matrix, n, m, *pj);
    // Удаление строки
    delete_row(matrix, n, m - 1, *pi);
    // Вывод матрицы
    printf("Полученная матрица:\n");
    print_matrix(matrix, n - 1, m - 1);
}
