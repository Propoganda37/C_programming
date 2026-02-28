#include <check.h>
#include <stdlib.h>
#include "libprocess.h"

// Нет четных чисел
START_TEST(test_insert_no_even)
{
    int rc;
    size_t size1 = 3, size2 = 3;
    int array1[] = {1, 3, 5};
    int array2[3];
    int expected[] = {1, 3, 5};
    rc = copy_and_insert(array1, size1, array2, &size2, 1);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(array2, expected, size2 * sizeof(int));
}
END_TEST

// Есть несколько четных чисел
START_TEST(test_insert_some_even)
{
    int rc;
    size_t size1 = 4, size2 = 6;
    int array1[] = {1, 2, 3, 4};
    int array2[6];
    int expected[] = {1, 2, 5, 3, 4, 5};
    rc = copy_and_insert(array1, size1, array2, &size2, 5);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(array2, expected, size2 * sizeof(int));
}
END_TEST

// Все числа четные
START_TEST(test_insert_all_even)
{
    int rc;
    size_t size1 = 4, size2 = 8;
    int array1[] = {2, 4, 6, 8};
    int array2[8];
    int expected[] = {2, 5, 4, 5, 6, 5, 8, 5};

    rc = copy_and_insert(array1, size1, array2, &size2, 5);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(array2, expected, size2 * sizeof(int));
}
END_TEST

// Определение размера массива
START_TEST(test_insert_count_size)
{
    int rc;
    size_t size1 = 5, size2;
    int array1[] = {1, 2, 3, 4, 5};
    rc = copy_and_insert(array1, size1, NULL, &size2, 5);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(size2, 7);
}
END_TEST


// Негативы
// Размер входного массива 0
START_TEST(test_insert_zero_size)
{
    int rc;
    size_t size1 = 0, size2;
    int array1[1];
    rc = copy_and_insert(array1, size1, NULL, &size2, 5);

    ck_assert_int_eq(rc, ERR_EMPTY);
}
END_TEST

Suite* insert_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Тестовый набор для тестирования функции copy_and_insert
    s = suite_create("insert");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_insert_all_even);
    tcase_add_test(tc_pos, test_insert_no_even);
    tcase_add_test(tc_pos, test_insert_some_even);
    tcase_add_test(tc_pos, test_insert_count_size);

    suite_add_tcase(s, tc_pos);
    
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_insert_zero_size);

    suite_add_tcase(s, tc_neg);
    return s;
}
