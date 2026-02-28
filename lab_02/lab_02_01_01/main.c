// 1 Вариант. Программа находит нечётные элементы в массиве и выводит их произведение
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define N 10

// Функция для нахождения произведения нечётных элементов
int product(int mas[], size_t n)
{
    int p = 1, flag = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (abs(mas[i]) % 2 == 1)
        {
            flag = 1;
            p *= mas[i];
        }
    }
    if (flag)
    {
        return p;
    }
    else
    {
        return 0;
    }
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
    int prod = product(mas, n);
    // Проверка отсутствия нечётных элементов
    if (prod == 0)
    {
        printf("В массиве нет нечётных элементов\n");
        return 2;
    }
    // Вывод результата
    else
    {
        printf("Произведение нечётных элементов равно %d\n", prod);
    }
}

