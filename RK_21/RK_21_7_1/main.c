// Программа заменяет в числе все чётные цифры на единицу
#include <stdio.h>

// Функция для получения нового числа
int change_number(int n)
{
    int new_n = 0, i = 1;
    while (n > 0)
    {
        if (n % 10 % 2 == 0)
        {
            new_n = 1 * i + new_n;
        }
        else
        {
            new_n = n % 10 * i + new_n;
        }
        n /= 10;
        i *= 10;
    }
    return new_n;
}

int main(void)
{
    int number;
    // Ввод числа и проверка
    printf("Введите натуральное число:\n");
    if (scanf("%d", &number) != 1)
    {
        printf("Нужно ввести натуральное число\n");
        return 1;
    }
    if (number <= 0)
    {
        printf("Нужно ввести натуральное число\n");
        return 1;
    }
    printf("Новое число: %d\n", change_number(number));
    return 0;
}

