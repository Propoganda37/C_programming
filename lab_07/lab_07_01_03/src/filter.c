// Функция фильтр. В массиве остаются все элементы до последнего отрицательного элемента

#include <stdlib.h>
#include "const.h"
#include "filter.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pe_src <= pb_src || pe_src == NULL || pb_src == NULL)
    {
        return ERR_FILTER;
    }
    const int *pi, *pe_new = pe_src;
    int count = pe_src - pb_src;
    for (pi = pe_src - 1; pi >= pb_src; pi--)
    {
        if (*pi < 0)
        {
            count = pi - pb_src;
            pe_new = pi;
            break;
        }
    }
    if (count == 0)
    {
        return ERR_EMPTY_FILTER;
    }
    int *arr = calloc(count, sizeof(int));
    if (arr == NULL)
    {
        return ERR_ALLOC;
    }
    int *arr_i = arr;
    for (pi = pb_src; pi < pe_new; pi++)
    {
        *arr_i = *pi;
        arr_i++;
    }
    *pb_dst = arr;
    *pe_dst = arr + count;
    return 0;
}
