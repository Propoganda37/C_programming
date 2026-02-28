// 1 Вариант. Программа вставляет числа Фибоначи после чисел, кратных трём
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define N 20

// Функция вывода массива
void print_mas(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
}

// Функция вставки элемента
void insert(int mas[], size_t n, size_t pos, int fib)
{
    for (size_t i = n + 1; i > pos; i--)
    {
        mas[i] = mas[i - 1];
    }
    mas[pos] = fib;
}

// Функция ввода длины массива
size_t get_size()
{
    size_t n;
    int rc = scanf("%zu", &n);
    // Проверка длины
    if (rc != 1 || n < 1 || n > 10)
    {
        return 0;
    }
    return n;
}

// Функция заполнения массива
int create_mas(int mas[], size_t n)
{
    // Ввод элементов
    for (size_t i = 0; i < n; i++)
    {
        int rc = scanf("%d", &mas[i]);
        if (rc != 1)
        {
            return 0;
        }
    }
    return 1;
}

size_t insert_fib(int mas[], size_t n)
{
    int fib0 = 0, fib1 = 1;
    size_t i = 0;
    while (i < n)
    {
        if (abs(mas[i]) % 3 == 0)
        {
            insert(mas, n, i + 1, fib0);
            n++;
            i++;
            fib1 += fib0;
            fib0 = fib1 - fib0;
        }
        i++;
    }
    return n;
}

int main(void)
{
    int mas[N] = { 0 };
    printf("Введите число элементов в массиве (от одного до десяти):\n");
    size_t n = get_size();
    // Проверка длины
    if (n == 0)
    {
        printf("Нужно ввести целое число от одного до десяти\n");
        return 1;
    }
    // Ввод элементов
    printf("Введите элементы массива:\n");
    if (create_mas(mas, n) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    /*
    printf("Введённый массив:\n");
    print_mas(mas, n);
    */
    n = insert_fib(mas, n);
    printf("Полученный массив:\n");
    print_mas(mas, n);
}

