#include <check.h>
#include <stdlib.h>
#include "libprocess.h"

// Позитивы
// 1 простое число
START_TEST(test_prime_one_num)
{
    int rc, num = 1;
    int a[1];
    int expected[] = { 2 };
    rc = fill_primes(a, num);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(a, expected, num * sizeof(int));
}
END_TEST

// 2 простых числа
START_TEST(test_prime_two_num)
{
    int rc, num = 2;
    int a[2];
    int expected[] = { 2, 3 };
    rc = fill_primes(a, num);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(a, expected, num * sizeof(int));
}
END_TEST


// более 2 простых чисел
START_TEST(test_prime_more_than_two)
{
    int rc, num = 5;
    int a[5];
    int expected[] = { 2, 3, 5, 7, 11 };
    rc = fill_primes(a, num);

    ck_assert_int_eq(rc, OK);
    ck_assert_mem_eq(a, expected, num * sizeof(int));
}
END_TEST



// Негативы
// 0 чисел
START_TEST(test_prime_zero_num)
{
    int rc, num = 0;
    int a[1];
    rc = fill_primes(a, num);

    ck_assert_int_eq(rc, ERR_SIZE);
}
END_TEST

// отрицательное количество чисел Фибоначчи
START_TEST(test_prime_neg_num)
{
    int rc, num = -5;
    int a[1];
    rc = fill_primes(a, num);

    ck_assert_int_eq(rc, ERR_SIZE);
}
END_TEST

Suite* prime_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Тестовый набор для тестирования функции fill_primes
    s = suite_create("fill_primes");

    // Создадим тестовый случай из позитивных тестов
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_prime_one_num);
    tcase_add_test(tc_pos, test_prime_two_num);
    tcase_add_test(tc_pos, test_prime_more_than_two);

    suite_add_tcase(s, tc_pos);
    

    // Создадим тестовый случай из негативных тестов
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_prime_zero_num);
    tcase_add_test(tc_neg, test_prime_neg_num);

    suite_add_tcase(s, tc_neg);
    return s;
}
