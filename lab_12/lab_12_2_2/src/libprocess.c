#include <stdlib.h>
#include "libprocess.h"

// Функция для проверки, является ли число простым
int is_prime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    if (num <= 3)
    {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0)
    {
        return 0;
    }
    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Функция для заполнения массива простыми числами
int fill_primes(int *array, int size)
{
    if (size <= 0)
    {
        return ERR_SIZE;
    }
    int count = 0;
    int num = 2;
    while (count < size)
    {
        if (is_prime(num))
        {
            array[count] = num;
            count++;
        }
        num++;
    }
    return OK;
}


// Функция для переписывания элементов из одного массива в другой
int copy_and_insert(int *src, size_t src_size, int *dest, size_t *dest_size, int number_to_insert)
{
    if (src_size <= 0)
    {
        return ERR_EMPTY;
    }
    size_t j = 0;
    for (size_t i = 0; i < src_size; i++)
    {
        if (dest)
        {
            dest[j] = src[i];
        }
        j++;
        if (src[i] % 2 == 0)
        {
            if (dest)
            {
                dest[j] = number_to_insert;
            }
            j++;
        }
    }
    *dest_size = j;
    return OK;
}
