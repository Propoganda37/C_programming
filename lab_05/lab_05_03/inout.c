#include <stdio.h>
#include "const.h"
#include "inout.h"

// Функция для вывода ошибок
void print_error(int rc)
{
    switch (rc)
    {
        case ERR_ARG:
            printf("Вы ввели неправильные параметры командной строки\n");
            break;
        case ERR_OPEN:
            printf("Возникла ошибка при открытии файла\n");
            break;
        case ERR_EMPTY:
            printf("В файле должно быть хотя бы одно число\n");
            break;
        case ERR_IO:
            printf("Неверные данные в файле\n");
            break;
        case ERR_NUM:
            printf("Нужно ввести положительное число\n");
            break;
        case ERR_SIZE:
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
    }
}

// Функция для получения бинарного файла из текстового
int text_to_binary(const char *t_f_name, const char *b_f_name)
{
    FILE *t_f = fopen(t_f_name, "r");
    FILE *b_f = fopen(b_f_name, "wb");
    if (t_f == NULL || b_f == NULL)
    {
        if (t_f != NULL)
        {
            fclose(t_f);
        }
        if (b_f != NULL)
        {
            fclose(b_f);
        }
        return ERR_OPEN;
    }
    int num;
    while (fscanf(t_f, "%d", &num) == 1)
    {
        fwrite(&num, sizeof(int), 1, b_f);
    }
    fclose(t_f);
    fclose(b_f);
    return 0;
}

// Функция для получения текстового файла из бинарного
int binary_to_text(const char *b_f_name, const char *t_f_name)
{
    FILE *b_f = fopen(b_f_name, "rb");
    FILE *t_f = fopen(t_f_name, "w");
    if (t_f == NULL || b_f == NULL)
    {
        if (t_f != NULL)
        {
            fclose(t_f);
        }
        if (b_f != NULL)
        {
            fclose(b_f);
        }
        return ERR_OPEN;
    }
    int num;
    while (fread(&num, sizeof(int), 1, b_f))
    {
        fprintf(t_f, "%d ", num);
    }
    fclose(b_f);
    fclose(t_f);
    return 0;
}
