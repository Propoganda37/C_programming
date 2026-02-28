// 5 вариант. Программа выводит число по одной цифре за раз
#include <stdio.h>
#include <math.h>

// Функция для получения первой цифры числа
int get_number(int num, int i)
{
    i--;
    return num / (int)pow(10, i);
}

int main(void)
{
    int number, rc, signs;

    // Ввод
    printf("Введите натуральное число:\n");
    rc = scanf("%d", &number);

    // Проверки ввода
    if (rc != 1)
    {
        printf("Неверный ввод\n");
        return 1;
    }
    else if (number <= 0)
    {
        printf("Число должно быть больше нуля\n");
        return 1;
    }
    // Вывод числа
    else
    {
        signs = (int)floor(log10f((float)number) + 1);
        printf("Введённое число: ");
        while (signs > 0)
        {
            printf("%d", get_number(number, signs));
            number -= (int)(get_number(number, signs) * pow(10, signs - 1));
            signs--;
        }
        printf(" \n");
        return 0;
    }
}

