// 2 Вариант. Программа сортирует массив по возрастанию с помощью метода вставок
#include <stdio.h>
#include <stddef.h>
#define N 10

// Функция вывода массива
void print_mas(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", mas[i]);
    }
    printf("\n");
}

// Функция сортировки массива
void selection_sort(int mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        size_t max_ind = 0;
        for (size_t j = 1; j < n - i; j++)
        {
            if (mas[j] > mas[max_ind])
            {
                max_ind = j;
            }
        }
        int a = mas[n - i - 1];
        mas[n - i - 1] = mas[max_ind];
        mas[max_ind] = a;
    }
}

// Функция заполнения массива
size_t create_mas(int mas[])
{
    printf("Введите элементы массива:\n");
    size_t n = 0;
    // Проверка длины
    if (scanf("%d", &mas[n]) != 1)
    {
        printf("Нельзя ввести пустой массив\n");
        return 0;
    }
    n++;
    int el;
    // Ввод элементов
    while (scanf("%d", &el) == 1)
    {
        if (n < 10)
        {
            mas[n] = el;
        }
        n++;
    }
    return n;
}

int main(void)
{
    int mas[N] = { 0 };
    size_t n = create_mas(mas);
    // Проверки ввода
    if (n == 0)
    {
        return 1;
    }
    /*
    printf("Введённый массив:\n");
    print_mas(mas, n);
    */
    int code;
    // Проверка переполнения ввода
    if (n > 10)
    {
        code = 100;
        n = 10;
    }
    else
    {
        code = 0;
    }
    selection_sort(mas, n);
    // Вывод результата
    printf("Полученный массив:\n");
    print_mas(mas, n);
    return code;
}

