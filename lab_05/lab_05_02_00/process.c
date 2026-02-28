#include <stdio.h>
#include <math.h>
#include "const.h"
#include "process.h"

// Функция для нахождения среднего значения
int count_average(FILE *f, double *avg)
{
    int count = 0;
    double num;
    while (fscanf(f, "%lf", &num) == 1)
    {
        *avg += num;
        count++;
    }
    if (!feof(f))
    {
        return ERR_IO;
    }
    if (count == 0)
    {
        return ERR_EMPTY;
    }
    *avg /= count;
    return 0;
}

// Функция для нахождения ближайшего к среднему числа
double find_nearest(FILE *f, double avg)
{
    double min_dist = 0, num = 0, nearest = 0;
    fscanf(f, "%lf", &num);
    min_dist = fabs(num - avg);
    nearest = num;
    while (fscanf(f, "%lf", &num) == 1)
    {
        if (fabs(num - avg) < min_dist)
        {
            min_dist = fabs(num - avg);
            nearest = num;
        }
    }
    return nearest;
}
