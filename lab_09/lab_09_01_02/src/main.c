/*
Программа считывает информацию о предметах (название, масса, объём)
Можно вывести информацию о предметах на экран, отсортировать предметы по плотности
и найти все предметы, названия которых начинаются на заданную подстроку
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "item.h"
#include "item_arr.h"

int main(int argc, char **argv)
{
    int rc = ERR_OK;
    size_t n = 0;
    item_t *items = NULL;
    // чтение содержимого файла
    if (argc >= 2)
    {
        FILE *f = fopen(argv[1], "r");
        if (f == NULL)
        {
            //print_error(ERR_FILE);
            return ERR_FILE;
        }
        rc = itemar_read(f, &items, &n);
        if (rc != ERR_OK)
        {
            //print_error(rc);
            fclose(f);
            return rc;
        }
        fclose(f);
    }
    // сортировка
    if (argc == 2)
    {
        itemar_sort(items, n);
        itemar_print(stdout, items, n);
    }
    // вывод содержимого файла
    else if (argc == 3 && strcmp(argv[2], "ALL") == 0)
    {
        itemar_print(stdout, items, n);
    }
    // поиск по подстроке
    else if (argc == 3 && strcmp(argv[2], "ALL") != 0)
    {
        item_t *found_arr = NULL;
        size_t new_n;
        rc = find(items, n, argv[2], &found_arr, &new_n);
        if (rc != ERR_OK)
        {
            //print_error(rc);
            free_items(items, n);
            return rc;
        }
        itemar_print(stdout, found_arr, new_n);
        free(found_arr);
    }
    else
    {
        //print_error(ERR_ARGS);
        return ERR_ARGS;
    }
    free_items(items, n);
    return rc;
}
