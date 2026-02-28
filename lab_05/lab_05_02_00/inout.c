#include <stdio.h>
#include "const.h"
#include "inout.h"

void print_error(int rc)
{
    switch (rc)
    {
        case ERR_NO_NAME:
            printf("Нужно ввести имя файла при запуске программы\n");
            break;
        case ERR_OPEN:
            printf("Возникла ошибка при открытии файла\n");
            break;
        case ERR_EMPTY:
            printf("В файле должно быть хотя бы одно число\n");
            break;
        case ERR_IO:
            printf("Неверные данные в файле\n");
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
    }
}
