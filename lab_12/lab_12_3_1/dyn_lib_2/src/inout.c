// Функции ввода и вывода

#include <stdio.h>
#include <stdlib.h>
#include "inout.h"
#include "const.h"


// Функция для чтения чисел из файла
int read_numbers(FILE *f, int **pb, int **pe)
{
    int num;
    size_t count = 0;
    while (fscanf(f, "%d", &num) == 1)
    {
        count += 1;
    }
    if (!feof(f))
    {
        return ERR_IO;
    }
    if (count == 0)
    {
        return ERR_EMPTY;
    }
    int *arr = calloc(count, sizeof(int));
    if (arr == NULL)
    {
        return ERR_ALLOC;
    }
    *pb = arr;
    *pe = arr + count;
    rewind(f);
    int *pi;
    for (pi = *pb; pi < *pe; pi++)
    {
        fscanf(f, "%d", pi);
    }
    return 0;
}

// Функция для вывода полученного массива
void print_numbers(FILE *f, int *pb, int *pe)
{
    for (int *pi = pb; pi < pe; pi++)
    {
        fprintf(f, "%d ", *pi);
    }
}

// Функция для вывода ошибки
void print_error(int rc)
{
    switch (rc)
    {
        case ERR_EMPTY:
            printf("Пустой файл\n");
            break;
        case ERR_OPEN:
            printf("Ошибка при открытии файла\n");
            break;
        case ERR_ARG:
            printf("Введены некорректные аргументы\n");
            break;
        case ERR_IO:
            printf("Некорректные данные в файле\n");
            break;
        case ERR_ALLOC:
            printf("Ошибка выделения памяти\n");
            break;
        case ERR_FILTER:
            printf("На вход фильтру поступили некорректные данные");
            break;
        case ERR_EMPTY_FILTER:
            printf("После фильтрации массив стал пустым\n");
            break;
        case ERR_LIB:
            printf("Не удалось открыть библиотеку\n");
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
            break;
    }
}