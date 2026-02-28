#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "const.h"
#include "item.h"

// чтение информации об одном предмете
int item_read(FILE *f, item_t *pitem)
{
    char tmp[2];
    pitem->name = NULL;
    size_t len = 0;
    ssize_t read = 0;
    // чтение названия предмета
    read = getline(&(pitem->name), &len, f);
    if (read == -1)
    {
        free(pitem->name);
        return ERR_DATA;
    }
    if (pitem->name == NULL)
    {
        return ERR_ALLOC;
    }
    if (pitem->name[read - 1] == '\n')
    {
        pitem->name[read - 1] = '\0';
        read--;
    }
    if (read <= 0)
    {
        free(pitem->name);
        return ERR_DATA;
    }
    // чтение массы и объема
    if (fscanf(f, "%lf %lf", &pitem->m, &pitem->v) != 2)
    {
        free(pitem->name);
        return ERR_DATA;
    }
    if (pitem->m <= 0 || pitem->v <= 0)
    {
        free(pitem->name);
        return ERR_DATA;
    }
    fgets(tmp, sizeof(tmp), f);
    return ERR_OK;
}

// Вывод информации об одном предмете
void item_print(FILE* out_file, item_t *item)
{
    fprintf(out_file, "%s\n", item->name);
    fprintf(out_file, "%f\n", item->m);
    fprintf(out_file, "%f\n", item->v);
}

// сравнение предметов по плотности
int item_cmp_by_thickness(const void *item1, const void *item2)
{
    const item_t *item1_ptr, *item2_ptr;
    item1_ptr = item1;
    item2_ptr = item2;
    int diff = item1_ptr->m / item1_ptr->v < item2_ptr->m / item2_ptr->v;
    return diff;
}

// функция проверяет, начинается ли слово с подстроки
int find_item(const void *item, char *start)
{
    const item_t *item_ptr = item;
    size_t name_len = strlen(item_ptr->name);
    size_t start_len = strlen(start);
    if (name_len < start_len)
    {
        return 1;
    }
    for (size_t i = 0; i < start_len; i++)
    {
        if (item_ptr->name[i] != start[i])
        {
            return 1;
        }
    }
    return 0;
}
