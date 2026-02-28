#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "const.h"

typedef int (*fn_read_numbers_t)(FILE *, int **, int **);
typedef void (*fn_print_numbers_t)(FILE *, int *, int *);
typedef void (*fn_print_error_t)(int);
typedef void (*fn_mysort_t)(void *, size_t , size_t , int (*compare)(const void *, const void *));
typedef int (*fn_compare_numbers_t)(const void *, const void *);
typedef int (*fn_key_t)(const int *, const int *, int **, int **);

int main(int argc, char *argv[])
{
    void* lib = NULL;
    fn_read_numbers_t read_numbers;
    fn_print_numbers_t print_numbers;
    fn_print_error_t print_error;
    fn_mysort_t mysort;
    fn_compare_numbers_t compare_numbers;
    fn_key_t key;

    lib = dlopen("./libprocess.so", RTLD_NOW);

    if (!lib)
    {
        printf("Не удалось открыть библиотеку\n");
        return ERR_LIB;
    }
    read_numbers = (fn_read_numbers_t)dlsym(lib, "read_numbers");
    if (!read_numbers)
    {
        dlclose(lib);
        return ERR_FUNC;
    }
    print_numbers = (fn_print_numbers_t)dlsym(lib, "print_numbers");
    if (!print_numbers)
    {
        dlclose(lib);
        return ERR_FUNC;
    }
    print_error = (fn_print_error_t)dlsym(lib, "print_error");
    if (!print_error)
    {
        dlclose(lib);
        return ERR_FUNC;
    }
    mysort = (fn_mysort_t)dlsym(lib, "mysort");
    if (!mysort)
    {
        dlclose(lib);
        return ERR_FUNC;
    }
    compare_numbers = (fn_compare_numbers_t)dlsym(lib, "compare_numbers");
    if (!compare_numbers)
    {
        dlclose(lib);
        return ERR_FUNC;
    }
    key = (fn_key_t)dlsym(lib, "key");
    if (!key)
    {
        dlclose(lib);
        return ERR_FUNC;
    }

    // Проверка аргументов командной строки
    if (argc < 3 || argc > 4)
    {
        print_error(ERR_ARG);
        dlclose(lib);
        return ERR_ARG;
    }
    char flag = 0;
    if (argc == 4)
    {
        if (strcmp(argv[3], "f") == 0)
        {
            flag = 1;
        }
        else
        {
            print_error(ERR_ARG);
            dlclose(lib);
            return ERR_ARG;
        }
    }
    FILE *f_in, *f_out;
    int *pb = NULL, *pe = NULL;
    // Чтение чисел из файла
    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
    {
        print_error(ERR_OPEN);
        dlclose(lib);
        return ERR_OPEN;
    }
    int rc = read_numbers(f_in, &pb, &pe);
    fclose(f_in);
    if (rc != 0)
    {
        print_error(rc);
        dlclose(lib);
        return rc;
    }
    // Использование фильтра, если нужно
    if (flag)
    {
        int *pb_filtered = NULL, *pe_filtered = NULL;
        rc = key(pb, pe, &pb_filtered, &pe_filtered);
        free(pb);
        if (rc != 0)
        {
            print_error(rc);
            dlclose(lib);
            return rc;
        }
        pb = pb_filtered;
        pe = pe_filtered;
    }
    // Сортировка
    mysort(pb, (pe - pb), sizeof(int), compare_numbers);
    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        free(pb);
        print_error(ERR_OPEN);
        dlclose(lib);
        return ERR_OPEN;
    }
    // Вывод массива
    print_numbers(f_out, pb, pe);
    free(pb);
    fclose(f_out);
    dlclose(lib);
    return 0;
}