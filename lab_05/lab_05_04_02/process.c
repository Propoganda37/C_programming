#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "const.h"
#include "process.h"

// Функция для получения записи по позиции
struct product read_by_pos(FILE *f, size_t pos)
{
    struct product p;
    fseek(f, pos * sizeof(p), SEEK_SET);
    fread(&p, sizeof(p), 1, f);
    return p;
}

// Функция для записывания записи на указанную позицию
void write_by_pos(FILE *f, size_t pos, struct product p)
{
    fseek(f, pos * sizeof(p), SEEK_SET);
    fwrite(&p, sizeof(p), 1, f);
}

// Функция для проверки размера бинарного файла
int check_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(struct product) != 0)
    {
        return ERR_SIZE;
    }
    return 0;
}

// Функция, которая меняет записи местами
void swap(FILE *f, size_t pos1, size_t pos2)
{
    struct product temp = read_by_pos(f, pos1);
    write_by_pos(f, pos1, read_by_pos(f, pos2));
    write_by_pos(f, pos2, temp);
}

// Функция для сортировки записей в файле
int sort(FILE *f, FILE *f_new)
{
    if (check_size(f) != 0)
    {
        return ERR_SIZE;
    }
    fseek(f, 0, SEEK_END);
    size_t n = ftell(f) / sizeof(struct product);
    if (n == 0)
    {
        return ERR_EMPTY;
    }
    struct product cur;
    for (size_t i = 0; i < n; i++)
    {
        cur = read_by_pos(f, i);
        write_by_pos(f_new, i, cur);
    }
    struct product max;
    size_t imax;
    for (size_t i = 0; i < n; i++)
    {
        max = read_by_pos(f_new, i);
        imax = i;
        for (size_t j = i + 1; j < n; j++)
        {
            cur = read_by_pos(f_new, j);
            if (cur.price > max.price || (cur.price == max.price && cur.quantity > max.quantity))
            {
                max = cur;
                imax = j;
            }
        }
        swap(f_new, i, imax);
    }
    return 0;
}

int check_substr(char str[], size_t len_str, char substr[], size_t len_substr)
{
    if (len_substr > len_str)
    {
        return 1;
    }
    int flag = 0;
    for (size_t i = 0; i < len_substr; i++)
    {
        if (str[len_str - 1 - i] != substr[len_substr - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int find(FILE *f, char str[])
{
    if (check_size(f) != 0)
    {
        return ERR_SIZE;
    }
    fseek(f, 0, SEEK_END);
    size_t n = ftell(f) / sizeof(struct product);
    fseek(f, 0, SEEK_SET);
    if (n == 0)
    {
        return ERR_EMPTY;
    }
    struct product p;
    int flag = 0;
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if (check_substr(p.name, strlen(p.name), str, strlen(str)) == 0)
        {
            flag = 1;
            printf("%s\n", p.name);
            printf("%s\n", p.manufacter);
            printf("%u\n", p.price);
            printf("%u\n", p.quantity);
        }
    }
    if (flag == 0)
    {
        return ERR_NOT_FOUND;
    }
    return 0;
}
