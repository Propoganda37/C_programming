/*
1 вариант. Программа вычисляет площадь равнобедренной 
трапеции по двум основаниям и углу
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, fi, s;
    double pi = acos(0) * 2; // число пи
    // Ввод
    printf("Введите два основания и угол:\n");
    scanf("%lf%lf%lf", &a, &b, &fi);
    // Вычисление площади
    s = fabs(a * a - b * b) * tan(fi * pi / 180.0) / 4.0;
    printf("Площадь трапеции равна: %f \n", s);

    return 0;
}

