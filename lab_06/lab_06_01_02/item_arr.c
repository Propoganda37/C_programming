#include <stdio.h>
#include "error.h"
#include "item.h"
#include "item_arr.h"

// чтение файла в массив
int itemar_read(FILE *f, item_t *pitem, int *n)
{
    item_t tmp;
    int i = 0;
    int rc = ERR_OK;
    while (rc == ERR_OK)
    {
        rc = item_read(f, &tmp);
        if (rc == ERR_OK)
        {
            if (i < N_MAX)
            {
                pitem[i] = tmp;
                i++;
            }
            else
            {
                rc = ERR_OVERFLOW;
                break;
            }
        }
    }
    if (rc == ERR_DATA && feof(f))
    {
        rc = ERR_OK;
    }
    if (i == 0 && rc == ERR_OK)
    {
        return ERR_EMPTY_FILE;
    }
    *n = i;
    return rc;
}

// печать массива на экран
void itemar_print(FILE *f, item_t *pitems, int n)
{
    for (int i = 0; i < n; i++)
        item_print(f, &pitems[i]);
}

// сортировка массива
void itemar_sort(item_t *pitems, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (item_cmp_by_thickness(&pitems[j], &pitems[min_ind]))
            {
                min_ind = j;
            }
        }
        item_t temp = pitems[i];
        pitems[i] = pitems[min_ind];
        pitems[min_ind] = temp;
    }
}

// поиск слов по подстроке
int find(item_t *pitems, int n, char start[NAME_LEN + 2])
{
    int rc = ERR_NOT_FOUND;
    for (int i = 0; i < n; i++)
    {
        if (!find_item(&pitems[i], start))
        {
            item_print(stdout, &pitems[i]);
            rc = ERR_OK;
        }
    }
    return rc;
}

// вывод ошибок
void print_error(int rc)
{
    switch (rc)
    {
        case ERR_EMPTY_FILE:
            printf("Пустой файл\n");
            break;
        case ERR_DATA:
            printf("Неверные данные\n");
            break;
        case ERR_OVERFLOW:
            printf("Слишком много данных\n");
            break;
        case ERR_FILE:
            printf("Ошибка открытия файла\n");
            break;
        case ERR_NOT_FOUND:
            printf("Предметы не были найдены\n");
            break;
        case ERR_ARGS:
            printf("Ошибка аргументов командной строки\n");
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
    }
}
