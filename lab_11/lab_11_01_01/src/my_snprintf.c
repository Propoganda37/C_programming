#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

void int_to_string(long int num, char *str, char *digits, size_t *len, size_t size)
{
    char tmp[30];
    size_t i = 0, neg = 0;
    if (num < 0)
    {
        neg = 1;
        if (num == LONG_MIN)
        {
            num = -(num + 1);
            tmp[i++] = digits[num % 10 + 1];
            num /= 10;
        }
        else
        {
            num *= -1;
        }
    }
    if (num == 0)
    {
        tmp[i++] = '0';
    }
    while (num > 0)
    {
        tmp[i++] = digits[num % 10];
        num /= 10;
    }
    if (neg == 1)
    {
        tmp[i++] = '-';
    }
    while (i > 0 && *len + 1 < size)
    {
        if (str)
        {
            str[(*len)++] = tmp[--i];
        }
    }
    while (i > 0)
    {
        (*len)++;
        i--;
    }
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    long int num;
    size_t len = 0;
    char *digits = "0123456789";
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'l' && *(format + 1) == 'd')
            {
                format++;
                num = va_arg(args, long int);
                int_to_string(num, str, digits, &len, size);
            }
            else if (*format == '%')
            {
                if (len + 1 < size && str)
                {
                    str[len] = '%';
                }
                len++;
            }
            else if (*format == 's')
            {
                const char *s = va_arg(args, const char *);
                while (*s && len + 1 < size)
                {
                    if (str)
                    {
                        str[len++] = *s++;
                    }
                }
                while (*s++)
                {
                    len++;
                }
            }
        }
        else
        {
            if (len + 1 < size && str)
            {
                str[len] = *format;
            }
            len++;
        }
        format++;
    }

    if (size > 0 && str)
    {
        str[len < size - 1 ? len : size - 1] = '\0';
    }
    
    va_end(args);
    return (int)len;
}