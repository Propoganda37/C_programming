#include <stdio.h>
#include <string.h>
#include "process.h"

// Мой аналог функции strpbrk
char *my_strpbrk(const char *str, const char *sym)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        for (size_t j = 0; j < strlen(sym); j++)
        {
            if (str[i] == sym[j])
            {
                return (char *)(str + i);
            }
        }
    }
    return NULL;
}

// Мой аналог функции strspn
size_t my_strspn(const char *str, const char *sym)
{
    size_t len = 0;
    while (*str)
    {
        const char *p = sym;
        int flag = 0;
        while (*p)
        {
            if (*str == *p)
            {
                flag = 1;
                len++;
                break;
            }
            p++;
        }
        if (!flag)
        {
            break;
        }
        str++;
    }
    return len;
}

// Мой аналог функции strcspn
size_t my_strcspn(const char *str, const char *sym)
{
    size_t len = 0;
    while (*str)
    {
        const char *p = sym;
        int flag = 0;
        while (*p)
        {
            if (*str == *p)
            {
                flag = 1;
                break;
            }
            p++;
        }
        if (flag)
        {
            break;
        }
        len++;
        str++;
    }
    return len;
}

// Мой аналог функции strchr
char *my_strchr(const char *str, int sym)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if ((int)str[i] == sym)
        {
            return (char *)(str + i);
        }
    }
    if (sym == 0)
    {
        return (char *)(str + strlen(str));
    }
    return NULL;
}

// Мой аналог функции strrchr
char *my_strrchr(const char *str, int sym)
{
    char *p = NULL;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if ((int)str[i] == sym)
        {
            p = (char *)(str + i);
        }
    }
    if (sym == 0)
    {
        return (char *)(str + strlen(str));
    }
    return p;
}
