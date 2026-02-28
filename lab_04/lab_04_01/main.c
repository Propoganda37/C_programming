/*
Самостоятельная реализация функций strpbrk, strspn, strcspn, strchr, strrchr
*/
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "process.h"

int main(void)
{
    int tests = 0;
    char test_string[N][LEN] = { "aejr4nf j2o kj4", "weuhf8vx5ov fsju1 v", "5486 24668", "" };
    char test_strpbrk[N][LEN] = { "zxcj", "-=*+", "54", "yfw " };
    char test_strspn[N][LEN] = { "jr4aez0", "utkgn772", "8457", "i" };
    int test_strchr[N] = { '4', 'a', '6', 'x' };
    for (size_t i = 0; i < N; i++)
    {
        if (my_strpbrk(test_string[i], test_strpbrk[i]) != strpbrk(test_string[i], test_strpbrk[i]))
        {
            tests++;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (my_strspn(test_string[i], test_strspn[i]) != strspn(test_string[i], test_strspn[i]))
        {
            tests++;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (my_strcspn(test_string[i], test_strspn[i]) != strcspn(test_string[i], test_strspn[i]))
        {
            tests++;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (my_strchr(test_string[i], test_strchr[i]) != strchr(test_string[i], test_strchr[i]))
        {
            tests++;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        if (my_strrchr(test_string[i], test_strchr[i]) != strrchr(test_string[i], test_strchr[i]))
        {
            tests++;
        }
    }
    printf("Количество проваленных тестирований: %d\n", tests);
}
