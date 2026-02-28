// Вариант 5. Программа определяет пересекаются ли отрезки
#include <stdio.h>
#include <math.h>

// Функция для вычисления косого векторного произведения
float slanting_product(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - x2 * y1;
}

int main(void)
{
    // Ввод
    float xp, yp, xq, yq, xr, yr, xs, ys;
    printf("Введите координаты xp, yp, xq, yq, xr, yr, xs, ys:\n");
    int rc1 = scanf("%f%f%f%f%f%f%f%f", &xp, &yp, &xq, &yq, &xr, &yr, &xs, &ys);

    // Проверка ввода
    if (rc1 != 8)
    {
        printf("Неверный ввод\n");
        return 1;
    }
    // Проверка одинаковых координат концов отрезка
    else if ((fabs(xp - xq) < 0.0001 && fabs(yp - yq) < 0.0001) ||
        (fabs(xr - xs) < 0.0001 && fabs(xr - xs) < 0.0001))
    {
        printf("У отрезка должны отличаться координаты концов\n");
        return 1;
    }
    else
    {
        // Вычисление координат векторов
        float xpq = xq - xp;
        float ypq = yq - yp;
        float xpr = xr - xp;
        float ypr = yr - yp;
        float xps = xs - xp;
        float yps = ys - yp;
        float xsr = xr - xs;
        float ysr = yr - ys;
        float xsp = -xps;
        float ysp = -yps;
        float xsq = xq - xs;
        float ysq = yq - ys;
        
        // Проверка на пересечение и вывод ответа
        if (slanting_product(xpq, ypq, xpr, ypr) * slanting_product(xpq, ypq, xps, yps) < 0 &&
            slanting_product(xsr, ysr, xsp, ysp) * slanting_product(xsr, ysr, xsq, ysq) < 0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        return 0;
    }
}

