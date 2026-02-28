// 1 Вариант. Программа находит g(x)
#include <stdio.h>
#include <math.h>

// Функция для подсчёта следующего члена суммы
double count_next(float x, int i)
{
    return sqrt(x / i);
}

int main(void)
{
    float x; 
    double sum = 0;
    int i = 1;
    
    // Ввод значений
    printf("Введите последовательность неотрицательных чисел:\n");
    int rc = scanf("%f", &x);
    
    // Вычисление суммы
    while (rc == 1 && x >= 0)
    {
        sum += count_next(x, i);
        rc = scanf("%f", &x);
        i++;
    }
    
    // Проверка ввода
    if (rc != 1)
    {
        printf("Неверный ввод");
        return 1;
    }
    // Проверка последовательности на пустоту
    else if (i == 1)
    {
        printf("Последовательность должна быть непустой\n");
        return 1;
    }
    // Вывод результата
    else
    {
        printf("g(x): %f \n", sin(sum));
        return 0;
    }
}

