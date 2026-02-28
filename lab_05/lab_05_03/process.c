#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "process.h"

// Функция для получения числа по позиции
int get_number_by_pos(FILE *f, size_t pos)
{
    int num;
    fseek(f, pos * sizeof(num), SEEK_SET);
    fread(&num, sizeof(num), 1, f);
    return num;
}

// Функция для записывания числа на указанную позицию
void put_number_by_pos(FILE *f, size_t pos, int num)
{
    fseek(f, pos * sizeof(num), SEEK_SET);
    fwrite(&num, sizeof(num), 1, f);
}

// Функция для проверки размера бинарного файла
int check_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(int) != 0)
    {
        return ERR_SIZE;
    }
    fseek(f, 0, SEEK_SET);
    return 0;
}

// Функция для случайного заполнения файла
void random_fill(FILE *f, int count)
{
    for (int i = 0; i < count; i++)
    {
        int num = rand() % 10000;
        fwrite(&num, sizeof(num), 1, f);
    }
}

// Функция для вывода содержимого файла
int print_file(FILE *f)
{
    if (check_size(f) != 0)
    {
        return ERR_SIZE;
    }
    int num, flag = 0;
    while (fread(&num, sizeof(num), 1, f) == 1)
    {
        flag = 1;
        printf("%d ", num);
    }
    if (flag == 0)
    {
        return ERR_EMPTY;
    }
    printf("\n");
    return 0;
}

// Функция, которая меняет числа местами
void swap(FILE *f, size_t pos1, size_t pos2)
{
    int temp = get_number_by_pos(f, pos1);
    put_number_by_pos(f, pos1, get_number_by_pos(f, pos2));
    put_number_by_pos(f, pos2, temp);
}

// Функция для сортировки чисел в файле
int sort(FILE *f)
{
    if (check_size(f) != 0)
    {
        return ERR_SIZE;
    }
    fseek(f, 0, SEEK_END);
    size_t n = ftell(f) / sizeof(int);
    if (n == 0)
    {
        return ERR_EMPTY;
    }
    int min;
    size_t imin;
    for (size_t i = 0; i < n; i++)
    {
        min = get_number_by_pos(f, i);
        imin = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (get_number_by_pos(f, j) < min)
            {
                min = get_number_by_pos(f, j);
                imin = j;
            }
        }
        if (i != imin)
        {
            swap(f, i, imin);
        }
    }
    return 0;
}
