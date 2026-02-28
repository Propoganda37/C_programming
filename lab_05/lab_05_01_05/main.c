/*
Программа находит максимальное число подряд идущих одинаковых чисел
*/
#include <stdio.h>
#include "const.h"
#include "process.h"

int main(void)
{
    FILE *f = stdin;
    int result = 0, rc;
    printf("Введите числа:\n");
    rc = process(f, &result);
    if (rc == ERR_EMPTY)
    {
        printf("Вы должны ввести хотя бы одно число\n");
        return ERR_EMPTY;
    }
    else
    {
        printf("Максимальное число подряд идущих одинаковых чисел: %d\n", result);
    }
    return 0;
}
