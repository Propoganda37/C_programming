#include <string.h>
#include <ctype.h>
#include "const.h"
#include "process.h"

// Функция для проверки не закончилось ли число
int check_end(char str[], size_t i)
{
    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

// Функция для проверки экспоненциальной части
int check_exp(char str[], size_t i)
{
    if (str[i] == 'e' || str[i] == 'E')
    {
        i++;
        // Плюс или минус
        if (str[i] == '+' || str[i] == '-')
        {
            i++;
        }
        // Степень
        int digits = 0;
        while (strchr("0123456789", str[i]) != NULL && str[i] != '\0')
        {
            digits = 1;
            i++;
        }
        if ((digits == 1) && check_end(str, i))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return check_end(str, i);
}

// Функция для проверки строки на соответствие вещественному числу
int check(char str[])
{
    size_t i = 0;
    // Пробельные символы перед числом
    while (isspace(str[i]))
    {
        i++;
    }
    // Плюс или минус
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    // Целая часть
    int digits_before_dot = 0;
    while (strchr("0123456789", str[i]) != NULL && str[i] != '\0')
    {
        digits_before_dot = 1;
        i++;
    }
    if (digits_before_dot == 1)
    {
        // Точка и дробная часть
        if (str[i] == '.')
        {
            i++;
            while (strchr("0123456789", str[i]) != NULL && str[i] != '\0')
            {
                i++;
            }
        }
        return check_exp(str, i);
    }
    else
    {
        // Точка и дробная часть
        if (str[i] == '.')
        {
            i++;
            int digits = 0;
            while (strchr("0123456789", str[i]) != NULL && str[i] != '\0')
            {
                i++;
                digits = 1;
            }
            return check_exp(str, i) && (digits == 1);
        }
        return 0;
    }
}
