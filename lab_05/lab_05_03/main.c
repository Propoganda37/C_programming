/*
Программа может:
1) Создать бинарный файл и случайно заполнить его целыми числами
2) Вывести содержимое бинарного файла
3) Отсортировать числа в файле по возрастанию методом выбора
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "process.h"
#include "inout.h"

int main(int argc, char **argv)
{
    int rc;
    if (strcmp(argv[1], "import") == 0 && argc == 4)
    {
        rc = text_to_binary(argv[2], argv[3]);
        if (rc != 0)
        {
            print_error(rc);
            return rc;
        }
    }
    else if (strcmp(argv[1], "export") == 0 && argc == 4)
    {
        rc = binary_to_text(argv[2], argv[3]);
        if (rc != 0)
        {
            print_error(rc);
            return rc;
        }
    }
    else if (argc == 4 && strncmp(argv[1], "c", 1) == 0 && atoi(argv[2]) != 0)
    {
        FILE *f = fopen(argv[3], "wb");
        if (f == NULL)
        {
            print_error(ERR_OPEN);
            return ERR_OPEN;
        }
        int num = atoi(argv[2]);
        if (num <= 0)
        {
            print_error(ERR_NUM);
            return ERR_NUM;
        }
        random_fill(f, num);
        fclose(f);
    }
    else if (argc == 3 && strncmp(argv[1], "p", 1) == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
        {
            print_error(ERR_OPEN);
            return ERR_OPEN;
        }
        rc = print_file(f);
        if (rc != 0)
        {
            print_error(rc);
            return rc;
        }
        fclose(f);
    }
    else if (argc == 3 && strncmp(argv[1], "s", 1) == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            print_error(ERR_OPEN);
            return ERR_OPEN;
        }
        rc = sort(f);
        if (rc != 0)
        {
            print_error(rc);
            return rc;
        }
        fclose(f);
    }
    else
    {
        print_error(ERR_ARG);
        return ERR_ARG;
    }
    return 0;
}
