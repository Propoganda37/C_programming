/*
Вариант 11
*/
#include <stdio.h>
#include "const.h"
#include "inout.h"
#include "process.h"

int main()
{
    printf("Введите имя файла:\n");
    char name[LEN], best_author[LEN];
    int rc = get_string(name);
    if (rc == ERR_EMPTY)
    {
        printf("Нужно ввести что-нибудь\n");
        return ERR_EMPTY;
    }
    else if (rc == ERR_OVERFLOW)
    {
        printf("Слишком длинное имя файла\n");
        return ERR_OVERFLOW;
    }
    FILE *f = fopen("test.txt", "r");
    if (f == NULL)
    {
        printf("Возникла ошибка при открытии файла\n");
        return ERR_OPEN;
    }
    struct book info[LEN];
    rc = find_best(f, info, best_author);
    if (rc == ERR_DATA)
    {
        printf("Неверные данные в файле\n");
        return ERR_DATA;
    }
    else if (rc == ERR_IO)
    {
        printf("Возникла ошибка при чтении файла\n");
        return ERR_IO;
    }
    else if (rc == ERR_EMPTY)
    {
        printf("Пустой файл\n");
        return ERR_EMPTY;
    }
    fclose(f);
    printf("Самый популярный автор: %s", best_author);
    return 0;
}
