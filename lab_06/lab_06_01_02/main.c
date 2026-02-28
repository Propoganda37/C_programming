/*
Программа считывает информацию о предметах (название, масса, объём)
Можно вывести информаци. о предметах на экран, отсортировать предметы по плотности
и найти все предметы, названия которых начинаются на заданную подстроку
*/

#include <stdio.h>
#include <string.h>
#include "error.h"
#include "item.h"
#include "item_arr.h"

int main(int argc, char **argv)
{
    int rc = ERR_OK, n = 0;
    item_t items[N_MAX];
    // чтение содержимого файла
    if (argc >= 2)
    {
        FILE *f = fopen(argv[1], "r");
        if (f == NULL)
        {
            //print_error(ERR_FILE);
            return ERR_FILE;
        }
        rc = itemar_read(f, items, &n);
        if (rc != ERR_OK)
        {
            //print_error(rc);
            return rc;
        }
    }
    // сортировка
    if (argc == 2)
    {
        itemar_sort(items, n);
        itemar_print(stdout, items, n);
    }
    // вывод содержимого файла
    else if (argc == 3 && strncmp(argv[2], "ALL", 4) == 0)
    {
        itemar_print(stdout, items, n);
    }
    // поиск по подстроке
    else if (argc == 3 && strncmp(argv[2], "ALL", NAME_LEN + 2) != 0)
    {
        rc = find(items, n, argv[2]);
        if (rc != ERR_OK)
        {
            //print_error(rc);
            return rc;
        }
    }
    else
    {
        //print_error(ERR_ARGS);
        return ERR_ARGS;
    }
    return rc;
}
