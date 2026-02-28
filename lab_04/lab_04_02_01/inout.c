#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "inout.h"
#include "const.h"

// Функция для ввода строки
int get_string(char str[])
{
    if (fgets(str, LEN, stdin) == NULL || str[0] == '\n')
    {
        return ERR_EMPTY;
    }
    size_t n = strlen(str);
    if (n > 256)
    {
        return ERR_OVERFLOW;
    }
    if (str[n - 1] == '\n')
    {
        str[n - 1] = '\0';
    }
    return 0;
}

// Функция для вывода массива слов
void print_words(char words[][WORD_LEN], size_t wor)
{
    for (size_t i = 0; i < wor; i++)
    {
        if (i == wor - 1)
        {
            printf("%s", words[i]);
        }
        else
        {
            printf("%s ", words[i]);
        }
    }
    printf("\n");
}
