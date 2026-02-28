#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"
#include "item.h"

// чтение информации об одном предмете
int item_read(FILE *f, item_t *pitem)
{
    char buf[NAME_LEN + 3];
    size_t len;
    char tmp[11];
    double m, v;
    if (!fgets(buf, sizeof(buf), f))
    {
        return ERR_DATA;
    }
    len = strlen(buf);
    if (len && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
        len--;
    }
    if (!len || len > NAME_LEN)
    {
        return ERR_DATA;
    }
    if (fscanf(f, "%lf %lf", &m, &v) != 2)
    {
        return ERR_DATA;
    }
    if (m <= 0 || v <= 0)
    {
        return ERR_DATA;
    }
    fgets(tmp, sizeof(tmp), f);
    strcpy(pitem->name, buf);
    pitem->m = m;
    pitem->v = v;
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
int find_item(const void *item, char start[NAME_LEN + 2])
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
