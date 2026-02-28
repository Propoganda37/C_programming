/*
Программа находит сумму максимального и минимального элементов в массиве
и вставляет её в начало или конец массива в зависимости от чётности
*/
#include <stdio.h>
#include <stddef.h>
#define N 11

size_t get_size()
{
    size_t n;
    if (scanf("%zu", &n) != 1)
    {
        return 0;
    }
    if (n <= 0 || n > 10)
    {
        return 0;
    }
    return n;
}

int create_mas(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%d", &mas[i]) != 1)
        {
            return 0;
        }
    }
    return 1;
}

int find_max(int mas[], size_t n)
{
    int max = mas[0];
    for (size_t i = 1; i < n; i++)
    {
        if (mas[i] > max)
        {
            max = mas[i];
        }
    }
    return max;
}

int find_min(int mas[], size_t n)
{
    int min = mas[0];
    for (size_t i = 1; i < n; i++)
    {
        if (mas[i] < min)
        {
            min = mas[i];
        }
    }
    return min;
}

void insert_elem(int mas[], size_t n, int elem)
{
    if (elem % 2 == 0)
    {
        for (size_t i = n; i > 0; i--)
        {
            mas[i] = mas[i - 1];
        }
        mas[0] = elem;
    }
    else
    {
        mas[n] = elem;
    }
}

void print_mas(int mas[], size_t n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
}

int main(void)
{
    int mas[N];
    printf("Введите длину массива (от одного до десяти):\n");
    size_t n = get_size();
    if (n == 0)
    {
        printf("Нужно ввести число от одного до десяти\n");
        return 1;
    }
    printf("Введите элементы массива:\n");
    if (create_mas(mas, n) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    int max = find_max(mas, n);
    int min = find_min(mas, n);
    insert_elem(mas, n, max + min);
    printf("Полученный массив:\n");
    print_mas(mas, n + 1);
}

