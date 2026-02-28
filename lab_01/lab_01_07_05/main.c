/*
5 вариант. Программа считает приближённое значение функции, точное
значение функции, абсолютную и относительную погрешности
*/
#include <stdio.h>
#include <math.h>

// Функция для подсчёта следующего элемента
float count_next_elem(float prev, float x, int i)
{
    return prev * x * x * i / (i + 1);
}

int main(void)
{
    float x, eps;

    // Ввод
    printf("Введите х и точность:\n");
    int rc = scanf("%f%f", &x, &eps);

    // Проверка ввода
    if (rc != 2)
    {
        printf("Неверный ввод\n");
        return 1;
    }
    // Проверка точности
    else if (eps > 1 || 0 >= eps)
    {
        printf("Точность должна быть больше нуля и меньше или равна единицы\n");
        return 1;
    }
    // Проверка х
    else if (fabsf(x) >= 1)
    {
        printf("Модуль х должен быть меньше единицы\n");
        return 1;
    }
    else
    {
        // Вычисление приближённого значения
        int i = 1;
        float sum = 1, elem = 1, next_elem = count_next_elem(elem, x, i);
        while (next_elem >= eps)
        {
            elem = next_elem;
            sum += elem;
            i += 2;
            next_elem = count_next_elem(elem, x, i);
        }

        /*
        Вычисление точного значения, абсолютной и
        относительной погрешностей
        */
        float func_value = 1 / sqrtf(1 - x * x);
        float absolute_error = fabsf(func_value - sum);
        float relative_error = absolute_error / func_value;
        // Вывод результатов
        printf("Приближённое зачение: %f , точное значение: %f , абсолютная погрешность: %f ,"
            " относительная погрешность: %f \n", sum, func_value, absolute_error, relative_error);
        return 0;
    }
}

