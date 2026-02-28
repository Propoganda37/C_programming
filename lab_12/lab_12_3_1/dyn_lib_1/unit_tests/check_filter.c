#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "filter.h"
#include "const.h"
#include "check_filter.h"

// Негативные тесты

// Вместо начала массива NULL
START_TEST(test_filter_NULL_first)
{
    int arr[] = {1, 2, 3};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;

    int rc = key(NULL, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_FILTER);
}
END_TEST

// Вместо конца массива NULL
START_TEST(test_filter_NULL_second)
{
    int arr[] = {1, 2, 3};
    int *pb_dst, *pe_dst;

    int rc = key(arr, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_FILTER);
}
END_TEST

// Адрес конца массива меньше адреса начала
START_TEST(test_filter_pb_more_pe)
{
    int arr[] = {1, 2, 3};
    int *pb_dst, *pe_dst;

    int rc = key(arr, arr - 1, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_FILTER);
}
END_TEST

// После сортировки массив становится пустым
START_TEST(test_filter_empty)
{
    int arr[] = {-1, 2, 3, 4, 5};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;

    int rc = key(arr, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERR_EMPTY_FILTER);
}
END_TEST

// Позитивные тесты

// Один отрицательный элемент в массиве
START_TEST(test_filter_one_neg)
{
    int arr[] = {1, 2, 3, -4, 5};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;
    int expected[] = {1, 2, 3};
    size_t num_expected = sizeof(expected) / sizeof(expected[0]);

    int rc = key(arr, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(pb_dst, expected, num_expected * sizeof(int));
    free(pb_dst);
}
END_TEST

// Несколько отрицательных элементов в массиве
START_TEST(test_filter_many_neg)
{
    int arr[] = {1, -2, -3, -4, 5};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;
    int expected[] = {1, -2, -3};
    size_t num_expected = sizeof(expected) / sizeof(expected[0]);

    int rc = key(arr, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(pb_dst, expected, num_expected * sizeof(int));
    free(pb_dst);
}
END_TEST

// Один отрицательный элемент последний
START_TEST(test_filter_last_neg)
{
    int arr[] = {1, 2, 3, 4, -10};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;
    int expected[] = {1, 2, 3, 4};
    size_t num_expected = sizeof(expected) / sizeof(expected[0]);

    int rc = key(arr, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(pb_dst, expected, num_expected * sizeof(int));
    free(pb_dst);
}
END_TEST

// Нет отрицательных элементов в массиве
START_TEST(test_filter_no_neg)
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    int *pb_dst, *pe_dst;
    int expected[] = {1, 2, 3, 4, 5};
    size_t num_expected = sizeof(expected) / sizeof(expected[0]);

    int rc = key(arr, arr + num, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(pb_dst, expected, num_expected * sizeof(int));
    free(pb_dst);
}
END_TEST

Suite* filter_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("filter");
    // Негативы
    TCase *tc_neg = tcase_create("negatives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_neg, test_filter_empty); 
    tcase_add_test(tc_neg, test_filter_NULL_first); 
    tcase_add_test(tc_neg, test_filter_NULL_second); 
    tcase_add_test(tc_neg, test_filter_pb_more_pe); 

    // Добавление негативных тестов в набор
    suite_add_tcase(s, tc_neg);

    //Позитивы
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_filter_last_neg); 
    tcase_add_test(tc_pos, test_filter_many_neg); 
    tcase_add_test(tc_pos, test_filter_no_neg); 
    tcase_add_test(tc_pos, test_filter_one_neg);

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}