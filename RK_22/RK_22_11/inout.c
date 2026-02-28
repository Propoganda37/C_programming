#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "inout.h"
#include "const.h"

// Функция для ввода имени файла
int get_string(char str[])
{
    if (fgets(str, LEN, stdin) == NULL || str[0] == '\n')
    {
        return ERR_EMPTY;
    }
    size_t n = strlen(str);
    if (n > 50)
    {
        return ERR_OVERFLOW;
    }
    if (str[n - 1] == '\n')
    {
        str[n - 1] = '\0';
    }
    return 0;
}
