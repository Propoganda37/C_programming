#include <stdio.h>
#include "const.h"
#include "process.h"

// Функция нахождения максимального числа одинаковых элементов подряд
int process(FILE *f, int *result)
{
    int prev, curr, count = 1;
    if (fscanf(f, "%d", &prev) != 1)
    {
        return ERR_EMPTY;
    }
    while (fscanf(f, "%d", &curr) == 1)
    {
        if (curr == prev)
        {
            count++;
        }
        else
        {
            if (count > *result)
            {
                *result = count;
            }
            count = 1;
        }
        prev = curr;
    }
    if (count > *result)
    {
        *result = count;
    }
    return 0;
}
