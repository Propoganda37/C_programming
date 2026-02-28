#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "item.h"
#include "item_arr.h"

// чтение файла в массив
int itemar_read(FILE *f, item_t **items, size_t *n)
{
    item_t tmp;
    size_t i = 0;
    int rc = 0;
    while (!(rc = item_read(f, &tmp)))
    {
        i++;
        free(tmp.name);
    }
    if (!feof(f))
    {
        return rc;
    }
    if (i == 0)
    {
        return ERR_EMPTY_FILE;
    }
    *n = i;
    *items = malloc(i * sizeof(item_t));
    i = 0;
    rewind(f);
    while ((!(rc = item_read(f, &tmp))))
    {
        (*items)[i++] = tmp;
    }
    return ERR_OK;
}

// печать массива на экран
void itemar_print(FILE *f, item_t *pitems, size_t n)
{
    for (size_t i = 0; i < n; i++)
        item_print(f, &pitems[i]);
}

// сортировка массива
void itemar_sort(item_t *pitems, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        size_t min_ind = i;
        for (size_t j = i + 1; j < n; j++)
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
int find(item_t *pitems, size_t n, char *start, item_t **found_items, size_t *new_n)
{
    int rc = ERR_NOT_FOUND;
    *new_n = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (!find_item(&pitems[i], start))
        {
            rc = ERR_OK;
            (*new_n)++;
        }
    }
    if (rc == ERR_NOT_FOUND)
    {
        return rc;
    }
    *found_items = malloc(*new_n * sizeof(item_t));
    if (*found_items == NULL)
    {
        return ERR_ALLOC;
    }
    *new_n = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (!find_item(&pitems[i], start))
        {
            (*found_items)[(*new_n)++] = pitems[i];
        }
    }
    return rc;
}

void free_items(item_t *items, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(items[i].name);
    }
    free(items);
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
        case ERR_ALLOC:
            printf("Возникла ошибка при выделении памяти\n");
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
