#include <stdio.h>
#include <stdlib.h>
#include "my_snprintf.h"

int main(void)
{
    char str[20];
    my_snprintf(str, 20, "%s %ld", "aaaaa", 100);
    printf("%s", str);
    return 0;
}