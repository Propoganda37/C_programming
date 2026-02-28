/*
Вариант 11
*/
#include <stdio.h>
#include "const2.h"
#include "process.h"

int main(int argc, char** argv)
{
    char best_author[LEN];
    if (argc < 2)
    {
        printf("Нужно ввести имя файля при запуске программы\n");
        return ERR_NO_NAME;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Возникла ошибка при открытии файла\n");
        return ERR_OPEN;
    }
    struct book info[LEN];
    int rc = find_best(f, info, best_author);
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
    printf("Самый популярный автор: %s\n", best_author);
    return 0;
}
