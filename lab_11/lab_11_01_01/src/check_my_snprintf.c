#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "my_snprintf.h"

// Одно положительное число
START_TEST(test_one_pos_num)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld", 123L);
    my_res = snprintf(my_str, 30, "%ld", 123L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Одно отрицательное число
START_TEST(test_one_neg_num)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld", -123L);
    my_res = my_snprintf(my_str, 30, "%ld", -123L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Одно число ноль
START_TEST(test_one_zero)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld", 0L);
    my_res = my_snprintf(my_str, 30, "%ld", 0L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько положительных чисел
START_TEST(test_multiple_pos_nums)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %ld %ld", 123L, 456L, 789L);
    my_res = my_snprintf(my_str, 30, "%ld %ld %ld", 123L, 456L, 789L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько отрицательных чисел
START_TEST(test_multiple_neg_nums)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %ld %ld", -123L, -456L, -789L);
    my_res = my_snprintf(my_str, 30, "%ld %ld %ld", -123L, -456L, -789L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько чисел разных знаков и нули
START_TEST(test_mixed_nums_and_zeros)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %ld %ld %ld", 123L, -456L, 0L, 789L);
    my_res = my_snprintf(my_str, 30, "%ld %ld %ld %ld", 123L, -456L, 0L, 789L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько чисел, но не хватает места
/*
START_TEST(test_not_enough_space)
{
    char my_str[10], str[10];
    int my_res, res;
    res = snprintf(str, 10, "%ld %ld %ld", 123L, 456L, 789L);
    my_res = my_snprintf(my_str, 10, "%ld %ld %ld", 123L, 456L, 789L);
    ck_assert_int_eq(res, my_res);
}
END_TEST
*/

// Одна строка из одного символа
START_TEST(test_one_char_string)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s", "a");
    my_res = my_snprintf(my_str, 30, "%s", "a");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Одна строка из нескольких символов
START_TEST(test_multiple_char_string)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s", "hello");
    my_res = my_snprintf(my_str, 30, "%s", "hello");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько строк, каждая по одному символу
START_TEST(test_multiple_one_char_strings)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s %s %s", "a", "b", "c");
    my_res = my_snprintf(my_str, 30, "%s %s %s", "a", "b", "c");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько строк, каждая по несколько символов
START_TEST(test_multiple_char_strings)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s %s %s", "hello", "world", "test");
    my_res = my_snprintf(my_str, 30, "%s %s %s", "hello", "world", "test");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Несколько строк, но не хватает места
/*
START_TEST(test_not_enough_space_strings)
{
    char my_str[10], str[10];
    int my_res, res;
    res = snprintf(str, 10, "%s %s %s", "hello", "world", "test");
    my_res = my_snprintf(my_str, 10, "%s %s %s", "hello", "world", "test");
    ck_assert_int_eq(res, my_res);
}
END_TEST
*/

// Одно число, одна строка
START_TEST(test_one_num_one_string)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %s", 123L, "hello");
    my_res = my_snprintf(my_str, 30, "%ld %s", 123L, "hello");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Одна строка, одно число
START_TEST(test_one_string_one_num)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s %ld", "hello", 123L);
    my_res = my_snprintf(my_str, 30, "%s %ld", "hello", 123L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Число, строка, число
START_TEST(test_num_string_num)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %s %ld", 123L, "hello", 456L);
    my_res = my_snprintf(my_str, 30, "%ld %s %ld", 123L, "hello", 456L);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Строка, число, строка
START_TEST(test_string_num_string)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%s %ld %s", "hello", 123L, "world");
    my_res = my_snprintf(my_str, 30, "%s %ld %s", "hello", 123L, "world");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Перемешанные числа и строки
START_TEST(test_mixed_nums_and_strings)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%ld %s %ld %s", 123L, "hello", 456L, "world");
    my_res = my_snprintf(my_str, 30, "%ld %s %ld %s", 123L, "hello", 456L, "world");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Вывод процента
START_TEST(test_percent_output)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "%%");
    my_res = my_snprintf(my_str, 30, "%%");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Строка без спецификаторов
START_TEST(test_string_without_specifiers)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "hello world");
    my_res = my_snprintf(my_str, 30, "hello world");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Максимальный и минимальный long int
START_TEST(test_max_min_long_int)
{
    char my_str[60], str[60];
    int my_res, res;
    res = snprintf(str, 60, "%ld %ld", LONG_MAX, LONG_MIN);
    my_res = my_snprintf(my_str, 60, "%ld %ld", LONG_MAX, LONG_MIN);
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST

// Пустой формат
/*
START_TEST(test_empty_format)
{
    char my_str[30], str[30];
    int my_res, res;
    res = snprintf(str, 30, "");
    my_res = my_snprintf(my_str, 30, "");
    ck_assert_str_eq(str, my_str);
    ck_assert_int_eq(res, my_res);
}
END_TEST
*/
Suite* my_snprintf_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("my_snprintf");

    // Позитивы
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_one_pos_num);
    tcase_add_test(tc_pos, test_one_neg_num);
    tcase_add_test(tc_pos, test_one_zero);
    tcase_add_test(tc_pos, test_multiple_pos_nums);
    tcase_add_test(tc_pos, test_multiple_neg_nums);
    tcase_add_test(tc_pos, test_mixed_nums_and_zeros);
    //tcase_add_test(tc_pos, test_not_enough_space);
    tcase_add_test(tc_pos, test_one_char_string);
    tcase_add_test(tc_pos, test_multiple_char_string);
    tcase_add_test(tc_pos, test_multiple_one_char_strings);
    tcase_add_test(tc_pos, test_multiple_char_strings);
    //tcase_add_test(tc_pos, test_not_enough_space_strings);
    tcase_add_test(tc_pos, test_one_num_one_string);
    tcase_add_test(tc_pos, test_one_string_one_num);
    tcase_add_test(tc_pos, test_num_string_num);
    tcase_add_test(tc_pos, test_string_num_string);
    tcase_add_test(tc_pos, test_mixed_nums_and_strings);
    tcase_add_test(tc_pos, test_percent_output);
    tcase_add_test(tc_pos, test_string_without_specifiers);
    tcase_add_test(tc_pos, test_max_min_long_int);
    //tcase_add_test(tc_pos, test_empty_format);

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}