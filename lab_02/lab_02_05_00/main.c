// 0 Вариант. Программа находит максимальную сумму по условию
#include <stdio.h>
#include <stddef.h>
#define N 10

// Нахождение максимальной суммы
int max_sum(int *pa, int *pb)
{
    pb--;
    int max = *pa + *pb;
    pa++;
    pb--;
    while (pa <= pb)
    {
        if (*pa + *pb > max)
        {
            max = *pa + *pb;
        }
        pa++;
        pb--;
    }
    return max;
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

// Заполнение массива
int create_mas(int *pa, int *pb)
{
    // Ввод элементов
    while (pa < pb)
    {
        int rc = scanf("%d", pa);
        pa++;
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
    int *pa = mas;
    printf("Введите число элементов в массиве (от одного до десяти):\n");
    int *pb = pa + get_size();
    // Проверка на неправильный ввод
    if (pa == pb)
    {
        printf("Нужно ввести целое число от одного до десяти\n");
        return 1;
    }
    // Заполнение массива и проверка
    printf("Введите элементы массива:\n");
    if (create_mas(pa, pb) == 0)
    {
        printf("Нужно ввести целое число\n");
        return 1;
    }
    // Вывод результата
    printf("Максимальная сумма: %d\n", max_sum(pa, pb));
    return 0;
}

