#include <string.h>
#include <stdio.h>
#include "const.h"
#include "sort.h"
#include "filter.h"
#include "inout.h"

int main(int argc, char *argv[])
{
    // Проверка аргументов командной строки
    if (argc < 3 || argc > 4)
    {
        print_error(ERR_ARG);
        return ERR_ARG;
    }
    char flag = 0;
    if (argc == 4)
    {
        if (strcmp(argv[3], "f") == 0)
        {
            flag = 1;
        }
        else
        {
            print_error(ERR_ARG);
            return ERR_ARG;
        }
    }
    FILE *f_in, *f_out;
    int *pb = NULL, *pe = NULL;
    // Чтение чисел из файла
    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
    {
        print_error(ERR_OPEN);
        return ERR_OPEN;
    }
    int rc = read_numbers(f_in, &pb, &pe);
    fclose(f_in);
    if (rc != 0)
    {
        print_error(rc);
        return rc;
    }
    // Использование фильтра, если нужно
    if (flag)
    {
        int *pb_filtered = NULL, *pe_filtered = NULL;
        rc = key(pb, pe, &pb_filtered, &pe_filtered);
        free(pb);
        if (rc != 0)
        {
            print_error(rc);
            return rc;
        }
        pb = pb_filtered;
        pe = pe_filtered;
    }
    // Сортировка
    mysort(pb, (pe - pb), sizeof(int), compare_numbers);
    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        free(pb);
        print_error(ERR_OPEN);
        return ERR_OPEN;
    }
    // Вывод массива
    print_numbers(f_out, pb, pe);
    free(pb);
    fclose(f_out);
    return 0;
}
