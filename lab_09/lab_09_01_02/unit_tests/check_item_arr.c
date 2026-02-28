#include <check.h>
#include <stdlib.h>
#include "item_arr.h"
#include "check_item_arr.h"
#include "const.h"

// Сортировка
// Позитивные тесты

// Упорядоченный файл
START_TEST(test_sort_sorted)
{
    size_t n = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "iron", items[1].name = "gold", items[2].name = "silver";
    items[3].name = "stone", items[4].name = "diamond";
    items[0].m = 1.02, items[0].v = 10;
    items[1].m = 2, items[1].v = 9.3;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 3, items[3].v = 6.8463;
    items[4].m = 5.76, items[4].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(n * sizeof(item_t));
    expected_items[0].name = "iron", expected_items[1].name = "gold", expected_items[2].name = "silver";
    expected_items[3].name = "stone", expected_items[4].name = "diamond";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    expected_items[1].m = 2, expected_items[1].v = 9.3;
    expected_items[2].m = 2, expected_items[2].v = 8;
    expected_items[3].m = 3, expected_items[3].v = 6.8463;
    expected_items[4].m = 5.76, expected_items[4].v = 5;
    
    itemar_sort(items, n);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_str_eq(items[i].name, expected_items[i].name);
        ck_assert_double_eq(items[i].m, expected_items[i].m);
        ck_assert_double_eq(items[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
}
END_TEST

// Обратно упорядоченный файл
START_TEST(test_sort_reversed)
{
    size_t n = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "diamond", items[1].name = "stone", items[2].name = "silver";
    items[3].name = "gold", items[4].name = "iron";
    items[0].m = 5.76, items[0].v = 5;
    items[1].m = 3, items[1].v = 6.8463;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 2, items[3].v = 9.3;
    items[4].m = 1.02, items[4].v = 10;

    // Ожидаемый массив
    item_t *expected_items = malloc(n * sizeof(item_t));
    expected_items[0].name = "iron", expected_items[1].name = "gold", expected_items[2].name = "silver";
    expected_items[3].name = "stone", expected_items[4].name = "diamond";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    expected_items[1].m = 2, expected_items[1].v = 9.3;
    expected_items[2].m = 2, expected_items[2].v = 8;
    expected_items[3].m = 3, expected_items[3].v = 6.8463;
    expected_items[4].m = 5.76, expected_items[4].v = 5;
    
    itemar_sort(items, n);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_str_eq(items[i].name, expected_items[i].name);
        ck_assert_double_eq(items[i].m, expected_items[i].m);
        ck_assert_double_eq(items[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
}
END_TEST

// Случайный файл
START_TEST(test_sort_random)
{
    size_t n = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "diamond", items[1].name = "silver", items[2].name = "iron";
    items[3].name = "gold", items[4].name = "stone";
    items[0].m = 5.76, items[0].v = 5;
    items[1].m = 2, items[1].v = 8;
    items[2].m = 1.02, items[2].v = 10;
    items[3].m = 2, items[3].v = 9.3;
    items[4].m = 3, items[4].v = 6.8463;

    // Ожидаемый массив
    item_t *expected_items = malloc(n * sizeof(item_t));
    expected_items[0].name = "iron", expected_items[1].name = "gold", expected_items[2].name = "silver";
    expected_items[3].name = "stone", expected_items[4].name = "diamond";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    expected_items[1].m = 2, expected_items[1].v = 9.3;
    expected_items[2].m = 2, expected_items[2].v = 8;
    expected_items[3].m = 3, expected_items[3].v = 6.8463;
    expected_items[4].m = 5.76, expected_items[4].v = 5;
    
    itemar_sort(items, n);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_str_eq(items[i].name, expected_items[i].name);
        ck_assert_double_eq(items[i].m, expected_items[i].m);
        ck_assert_double_eq(items[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
}
END_TEST

// Сортировка одинаковых предметов
START_TEST(test_sort_same)
{
    size_t n = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "diamond", items[1].name = "diamond", items[2].name = "diamond";
    items[3].name = "diamond", items[4].name = "diamond";
    items[0].m = 5.76, items[0].v = 5;
    items[1].m = 5.76, items[1].v = 5;
    items[2].m = 5.76, items[2].v = 5;
    items[3].m = 5.76, items[3].v = 5;
    items[4].m = 5.76, items[4].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(n * sizeof(item_t));
    expected_items[0].name = "diamond", expected_items[1].name = "diamond", expected_items[2].name = "diamond";
    expected_items[3].name = "diamond", expected_items[4].name = "diamond";
    expected_items[0].m = 5.76, expected_items[0].v = 5;
    expected_items[1].m = 5.76, expected_items[1].v = 5;
    expected_items[2].m = 5.76, expected_items[2].v = 5;
    expected_items[3].m = 5.76, expected_items[3].v = 5;
    expected_items[4].m = 5.76, expected_items[4].v = 5;
    
    itemar_sort(items, n);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_str_eq(items[i].name, expected_items[i].name);
        ck_assert_double_eq(items[i].m, expected_items[i].m);
        ck_assert_double_eq(items[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
}
END_TEST

// Сортировка одного предмета
START_TEST(test_sort_one)
{
    size_t n = 1;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "diamond";
    items[0].m = 5.76, items[0].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(n * sizeof(item_t));
    expected_items[0].name = "diamond";
    expected_items[0].m = 5.76, expected_items[0].v = 5;
    
    itemar_sort(items, n);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_str_eq(items[i].name, expected_items[i].name);
        ck_assert_double_eq(items[i].m, expected_items[i].m);
        ck_assert_double_eq(items[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
}
END_TEST

// Поиск
// Позитивные тесты

// Один предмет подходит
START_TEST(test_find_one)
{
    size_t n = 5, m = 1;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "iron", items[1].name = "gold", items[2].name = "silver";
    items[3].name = "stone", items[4].name = "diamond";
    items[0].m = 1.02, items[0].v = 10;
    items[1].m = 2, items[1].v = 9.3;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 3, items[3].v = 6.8463;
    items[4].m = 5.76, items[4].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(m * sizeof(item_t));
    expected_items[0].name = "iron";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    
    item_t *found_arr = NULL;
    size_t new_n;
    int rc = find(items, n, "ir", &found_arr, &new_n);

    ck_assert_int_eq(new_n, m);
    ck_assert_int_eq(rc, ERR_OK);
    for (size_t i = 0; i < new_n; i++)
    {
        ck_assert_str_eq(found_arr[i].name, expected_items[i].name);
        ck_assert_double_eq(found_arr[i].m, expected_items[i].m);
        ck_assert_double_eq(found_arr[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
    free(found_arr);
}
END_TEST

// Несколько предметов подходит
START_TEST(test_find_some)
{
    size_t n = 5, m = 3;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "iron", items[1].name = "gold", items[2].name = "irsilver";
    items[3].name = "stone", items[4].name = "irdiamond";
    items[0].m = 1.02, items[0].v = 10;
    items[1].m = 2, items[1].v = 9.3;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 3, items[3].v = 6.8463;
    items[4].m = 5.76, items[4].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(m * sizeof(item_t));
    expected_items[0].name = "iron", expected_items[1].name = "irsilver";
    expected_items[2].name = "irdiamond";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    expected_items[1].m = 2, expected_items[1].v = 8;
    expected_items[2].m = 5.76, expected_items[2].v = 5;
    
    item_t *found_arr = NULL;
    size_t new_n;
    int rc = find(items, n, "ir", &found_arr, &new_n);

    ck_assert_int_eq(new_n, m);
    ck_assert_int_eq(rc, ERR_OK);
    for (size_t i = 0; i < new_n; i++)
    {
        ck_assert_str_eq(found_arr[i].name, expected_items[i].name);
        ck_assert_double_eq(found_arr[i].m, expected_items[i].m);
        ck_assert_double_eq(found_arr[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
    free(found_arr);
}
END_TEST

// Все предметы подходят
START_TEST(test_find_all)
{
    size_t n = 5, m = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "iron", items[1].name = "irgold", items[2].name = "irsilver";
    items[3].name = "irstone", items[4].name = "irdiamond";
    items[0].m = 1.02, items[0].v = 10;
    items[1].m = 2, items[1].v = 9.3;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 3, items[3].v = 6.8463;
    items[4].m = 5.76, items[4].v = 5;

    // Ожидаемый массив
    item_t *expected_items = malloc(m * sizeof(item_t));
    expected_items[0].name = "iron", expected_items[1].name = "irgold", expected_items[2].name = "irsilver";
    expected_items[3].name = "irstone", expected_items[4].name = "irdiamond";
    expected_items[0].m = 1.02, expected_items[0].v = 10;
    expected_items[1].m = 2, expected_items[1].v = 9.3;
    expected_items[2].m = 2, expected_items[2].v = 8;
    expected_items[3].m = 3, expected_items[3].v = 6.8463;
    expected_items[4].m = 5.76, expected_items[4].v = 5;
    
    item_t *found_arr = NULL;
    size_t new_n;
    int rc = find(items, n, "ir", &found_arr, &new_n);

    ck_assert_int_eq(new_n, m);
    ck_assert_int_eq(rc, ERR_OK);
    for (size_t i = 0; i < new_n; i++)
    {
        ck_assert_str_eq(found_arr[i].name, expected_items[i].name);
        ck_assert_double_eq(found_arr[i].m, expected_items[i].m);
        ck_assert_double_eq(found_arr[i].v, expected_items[i].v);
    }
    free(items);
    free(expected_items);
    free(found_arr);
}
END_TEST

// Нет подходящих предметов
START_TEST(test_find_nothing)
{
    size_t n = 5;
    // Входной массив
    item_t *items = malloc(n * sizeof(item_t));
    items[0].name = "iron", items[1].name = "irgold", items[2].name = "irsilver";
    items[3].name = "irstone", items[4].name = "irdiamond";
    items[0].m = 1.02, items[0].v = 10;
    items[1].m = 2, items[1].v = 9.3;
    items[2].m = 2, items[2].v = 8;
    items[3].m = 3, items[3].v = 6.8463;
    items[4].m = 5.76, items[4].v = 5;
    
    item_t *found_arr = NULL;
    size_t new_n;
    int rc = find(items, n, "irr", &found_arr, &new_n);

    ck_assert_int_eq(rc, ERR_NOT_FOUND);
    free(items);
}
END_TEST

Suite* item_arr_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("item_arr");
    // Негативы
    TCase *tc_neg = tcase_create("negatives");

    // Добавление в tc_neg функций-тестов
    tcase_add_test(tc_neg, test_find_nothing);

    // Добавление негативных тестов в набор
    suite_add_tcase(s, tc_neg);

    // Позитивы
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_sort_sorted);
    tcase_add_test(tc_pos, test_sort_reversed);
    tcase_add_test(tc_pos, test_sort_random);
    tcase_add_test(tc_pos, test_sort_same);
    tcase_add_test(tc_pos, test_sort_one);
    tcase_add_test(tc_pos, test_find_one);
    tcase_add_test(tc_pos, test_find_some);
    tcase_add_test(tc_pos, test_find_all);

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}