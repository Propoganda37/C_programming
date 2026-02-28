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
    else if (argc == 4 && strncmp(argv[1], "sb", 2) == 0)
    {
        FILE *f = fopen(argv[2], "rb+");
        FILE *f_new = fopen(argv[3], "wb");
        fclose(f_new);
        f_new = fopen(argv[3], "rb+");
        if (f == NULL || f_new == NULL)
        {
            if (f != NULL)
            {
                fclose(f);
            }
            if (f_new != NULL)
            {
                fclose(f_new);
            }
            print_error(ERR_OPEN);
            return ERR_OPEN;
        }
        rc = sort(f, f_new);
        if (rc != 0)
        {
            print_error(rc);
            fclose(f);
            fclose(f_new);
            return rc;
        }
        fclose(f);
        fclose(f_new);
        f_new = fopen(argv[3], "rb");
        print_file(f_new);
        fclose(f_new);
    }
    else if (argc == 4 && strncmp(argv[1], "fb", 2) == 0)
    {
        FILE *f = fopen(argv[2], "rb");
        if (f == NULL)
        {
            print_error(ERR_OPEN);
            return ERR_OPEN;
        }
        rc = find(f, argv[3]);
        if (rc != 0)
        {
            print_error(rc);
            fclose(f);
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
