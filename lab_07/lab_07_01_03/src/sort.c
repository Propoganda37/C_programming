// Функция сортировки

#include <stdlib.h>
#include "const.h"
#include "sort.h"

// Функция для сравнения двух целых чисел
int compare_numbers(const void *a, const void *b)
{
    const int *num_a = (int *)a;
    const int *num_b = (int *)b;
    return (*num_a - *num_b);
}

// Функция для обмена элементов
void swap(void *pa, void *pb, size_t size)
{
    char *pi_a = pa, *pi_b = pb;
    char ptemp;
    for (size_t i = 0; i < size; i++)
    {
        ptemp = *pi_a;
        *pi_a = *pi_b;
        *pi_b = ptemp;
        pi_a += 1;
        pi_b += 1;
    }
}

/*
Модифицированная сортировка пузырьком 1
Запоминает место последнего обмена и не заходит за него
*/
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *p_begin = (char *) base;
    char *pe = p_begin + (num - 1) * size;
    char *pj, *pb, *p_new_end;
    pb = p_begin;
    p_new_end = pe;
    do
    {
        p_new_end = p_begin;
        for (pj = pb; pj < pe; pj += size)
        {
            if (compare(pj, pj + size) > 0)
            {
                swap(pj, pj + size, size);
                p_new_end = pj + size;
            }
        }
        pe = p_new_end;
    } while (pb < pe);
}

