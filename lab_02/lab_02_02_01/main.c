// 1 Вариант. Программа создаёт новый массив из простых чисел из старого
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#define N 10

// Проверка числа на простоту
int prime_check(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i < ((int) sqrt(n)) + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Вывод массива
void print_mas(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
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

size_t create_new_mas(int new_mas[], int old_mas[], size_t n)
{
    size_t m = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (prime_check(old_mas[i]))
        {
            new_mas[m] = old_mas[i];
            m++;
        }
    }
    return m;
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
    int new_mas[N] = { 0 };
    size_t m = create_new_mas(new_mas, mas, n);
    // Ошибка, если не было простых чисел
    if (m == 0)
    {
        printf("В массиве нет простых чисел\n");
        return 2;
    }
    // Вывод результатов
    printf("Полученный массив:\n");
    print_mas(new_mas, m);
    return 0;
}

