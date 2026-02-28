/*
Программа проверяет, является ли введённая строка вещественным
числом в экспоненциальной форме
*/
#include <stdio.h>
#include <string.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int main(void)
{
    char str[LEN];
    int rc = get_string(str);
    if (rc == ERR_EMPTY)
    {
        printf("NO\n");
        return 0;
    }
    if (rc == ERR_OVERFLOW)
    {
        return ERR_OVERFLOW;
    }
    if (check(str) == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
