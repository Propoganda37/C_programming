/*
Программа находит в текстовом файле число, которое ближе всего
к среднему значению всех чисел
*/
#include <stdio.h>
#include "const.h"
#include "process.h"
#include "inout.h"

int main(int argc, char **argv)
{
    // Проверка аргументов командой строки
    if (argc != 2)
    {
        print_error(ERR_NO_NAME);
        return ERR_NO_NAME;
    }
    // Открытие файла
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        print_error(ERR_OPEN);
        return ERR_OPEN;
    }
    double avg = 0, nearest;
    // Подсчёт среднего
    int rc = count_average(f, &avg);
    if (rc != 0)
    {
        print_error(rc);
        return rc;
    }
    fclose(f);
    f = fopen(argv[1], "r");
    // Нахождение ближайшего к среднему
    nearest = find_nearest(f, avg);
    fclose(f);
    printf("Ближайшее к среднему число: %lf\n", nearest);
    return 0;
}
