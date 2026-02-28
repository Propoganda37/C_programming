#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "const.h"
#include "check_sort.h"

// Функция для сравнения двух вещественных чисел
int compare_double(const void *a, const void *b)
{
    const double *num_a = (double *)a;
    const double *num_b = (double *)b;
    return (*num_a - *num_b > 0);
}

// Функция для сравнения двух символов
int compare_char(const void *a, const void *b)
{
    const char *num_a = (char *)a;
    const char *num_b = (char *)b;
    return (*num_a - *num_b);
}

// Отсортированный массив
START_TEST(test_sort_sorted_array)
{
    size_t size = sizeof(int);
    //Массив для сортировки
    int arr[] = {-100, -83, -23, 0, 19, 23, 24};
    // Ожидаемый отсортированный массив
    int expected[] = {-100, -83, -23, 0, 19, 23, 24};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_numbers);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Массив, отсортированный в обратном порядке
START_TEST(test_sort_reversed_array)
{
    size_t size = sizeof(int);
    int arr[] = {100000, 234, 99, 87, 0, -4, -9, -123};
    int expected[] = {-123, -9, -4, 0, 87, 99, 234, 100000};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_numbers);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Случайный массив
START_TEST(test_sort_random_array)
{
    size_t size = sizeof(int);
    int arr[] = {5, 0, -31, 23, -6, -7, 5};
    int expected[] = {-31, -7, -6, 0, 5, 5, 23};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_numbers);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Массив из одинаковых чисел
START_TEST(test_sort_same_array)
{
    size_t size = sizeof(int);
    int arr[] = {5, 5, 5, 5, 5};
    int expected[] = {5, 5, 5, 5, 5};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_numbers);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Массив из одного числа
START_TEST(test_sort_one_elem_array)
{
    size_t size = sizeof(int);
    int arr[] = {914};
    int expected[] = {914};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_numbers);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Массив вещественных чисел
START_TEST(test_sort_double_array)
{
    size_t size = sizeof(double);
    double arr[] = {32.54, -4, 215.008, 1.1, -94.6, 0.4321};
    double expected[] = {-94.6, -4, 0.4321, 1.1, 32.54, 215.008};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_double);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

// Массив символов
START_TEST(test_sort_char_array)
{
    size_t size = sizeof(char);
    char arr[] = {'a', 'o', 'z', 'q', 'i'};
    char expected[] = {'a', 'i', 'o', 'q', 'z'};
    size_t num = sizeof(arr) / sizeof(arr[0]);

    mysort(arr, num, size, compare_char);
    ck_assert_mem_eq(arr, expected, size * num);
}
END_TEST

Suite* sort_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("sort");
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_sort_sorted_array); 
    tcase_add_test(tc_pos, test_sort_reversed_array); 
    tcase_add_test(tc_pos, test_sort_random_array); 
    tcase_add_test(tc_pos, test_sort_same_array); 
    tcase_add_test(tc_pos, test_sort_one_elem_array);
    tcase_add_test(tc_pos, test_sort_double_array); 
    tcase_add_test(tc_pos, test_sort_char_array); 

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}