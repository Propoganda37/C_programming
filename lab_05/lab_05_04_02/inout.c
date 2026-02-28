#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "const.h"
#include "inout.h"
#include "process.h"

// Функция для вывода ошибок
void print_error(int rc)
{
    switch (rc)
    {
        case ERR_ARG:
            printf("Вы ввели неправильные параметры командной строки\n");
            break;
        case ERR_EMPTY_STR:
            printf("Пустая строка в файле\n");
            break;
        case ERR_OVERFLOW:
            printf("Слишком длинная строка в файле\n");
            break;
        case ERR_DIGIT:
            printf("В файле записано не натуральное число\n");
            break;
        case ERR_OPEN:
            printf("Возникла ошибка при открытии файла\n");
            break;
        case ERR_DATA:
            printf("В файле неполная запись\n");
            break;
        case ERR_EMPTY:
            printf("В файле должна быть хотя бы одна запись\n");
            break;
        case ERR_SIZE:
            printf("В бинарном файле должны быть правильные записи\n");
            break;
        case ERR_NOT_FOUND:
            printf("Строки, заканчивающиеся на подстроку, не были найдены\n");
            break;
        default:
            printf("Возникла неизвестная ошибка\n");
    }
}

// Функция для чтения строки
int get_string(char str[], size_t len, FILE *f)
{
    if (fgets(str, len + 1, f) == NULL || str[0] == '\n')
    {
        return ERR_EMPTY_STR;
    }
    size_t n = strlen(str);
    if (n > len)
    {
        return ERR_OVERFLOW;
    }
    if (str[n - 1] == '\n')
    {
        str[n - 1] = '\0';
    }
    return 0;
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
    struct product p = { "", "", 0, 0 };
    int rc = 0, price = 0, quantity = 0;
    while (1)
    {
        if (feof(t_f))
        {
            break;
        }
        rc = get_string(p.name, 30, t_f);
        if (rc != 0)
        {
            break;
        }
        if (feof(t_f))
        {
            rc = ERR_DATA;
            break;
        }
        rc = get_string(p.manufacter, 15, t_f);
        if (rc != 0)
        {
            break;
        }
        if (feof(t_f))
        {
            rc = ERR_DATA;
            break;
        }
        rc = fscanf(t_f, "%d\n", &price);
        if (rc != 1 || price <= 0)
        {
            rc = ERR_DIGIT;
            break;
        }
        if (feof(t_f))
        {
            rc = ERR_DATA;
            break;
        }
        p.price = (uint32_t)price;
        rc = fscanf(t_f, "%d\n", &quantity);
        if (rc != 1 || quantity <= 0)
        {
            rc = ERR_DIGIT;
            break;
        }
        p.quantity = (uint32_t)quantity;
        fwrite(&p, sizeof(p), 1, b_f);
        rc = 0;
    }
    fclose(t_f);
    fclose(b_f);
    return rc;
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
    if (check_size(b_f) != 0)
    {
        fclose(t_f);
        fclose(b_f);
        return ERR_SIZE;
    }
    struct product p;
    fseek(b_f, 0, SEEK_SET);
    while (fread(&p, sizeof(p), 1, b_f) == 1)
    {
        fprintf(t_f, "%s\n", p.name);
        fprintf(t_f, "%s\n", p.manufacter);
        fprintf(t_f, "%u\n", p.price);
        fprintf(t_f, "%u\n", p.quantity);
    }
    fclose(b_f);
    fclose(t_f);
    return 0;
}

// Функция для вывода содержимого файла
int print_file(FILE *f)
{
    struct product p;
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        printf("%s\n", p.name);
        printf("%s\n", p.manufacter);
        printf("%u\n", p.price);
        printf("%u\n", p.quantity);
    }
    return 0;
}
