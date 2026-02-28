#include <check.h>
#include <stdlib.h>
#include "inout.h"
#include "slae.h"
#include "check_slae.h"
#include "check_operations.h"
#include "const.h"

// Позитивные тесты

// Коэффициенты положительные
START_TEST(test_slae_positives)
{
    size_t n = 3, m = 4;
    //Матрица СЛАУ
    double arr1[] = {78.54, 61.33, 99, 15.4,
                     1, 12.003, 785.11, 87.11,
                     1.01, 99.36, 456.77, 967.001};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;
    
    // Ожидаемый столбец решений
    double expected_arr[] = {-7.537145, 9.954329, -0.031632};
    
    int rc = solve(matrix1, n, m, &solution);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_double_eq_tol(solution[i], expected_arr[i], 1e-6);
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free(solution);
}
END_TEST

// Коэффициенты отрицательные
START_TEST(test_slae_negatives)
{
    size_t n = 3, m = 4;
    double arr1[] = {-703.54, -61.33, -949, -15.4,
                     -1, -142.0403, -785.1251, -87.11,
                     -17.01, -99.36, -456.77, -967.0101};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;
    
    double expected_arr[] = {7.347406, 47.574476, -8.505307};
    
    int rc = solve(matrix1, n, m, &solution);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_double_eq_tol(solution[i], expected_arr[i], 1e-6);
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free(solution);
}
END_TEST

// Коэффициенты разных знаков и нули
START_TEST(test_slae_different)
{
    size_t n = 3, m = 4;
    double arr1[] = {78.54, 61.33, -99, 15.4,
                     0, 12.003, -785.11, 87.11,
                     1.01, -99.36, -456.77, 967.001};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;

    double expected_arr[] = {6.571165, -8.554228, -0.241732};
    
    int rc = solve(matrix1, n, m, &solution);
    for (size_t i = 0; i < n; i++)
    {
        ck_assert_double_eq_tol(solution[i], expected_arr[i], 1e-6);
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free(solution);
}
END_TEST

// Негативные тесты

// Неправильные размеры матрицы для решения СЛАУ
START_TEST(test_slae_size)
{
    size_t n = 3, m = 5;
    double arr1[] = {78.54, 61.33, -99, 15.4, 1,
                     0, 12.003, -785.11, 87.11, 1,
                     1.01, -99.36, -456.77, 967.001, 1};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;
    
    int rc = solve(matrix1, n, m, &solution);
    ck_assert_int_eq(rc, ERR_SLAE_SIZE);
    free_matrix(matrix1, n);
}
END_TEST

// СЛАУ не имет решений
START_TEST(test_slae_no_sol)
{
    size_t n = 3, m = 4;
    double arr1[] = {78.54, 61.33, -99, 15.4,
                     1, 2, 3, 4,
                     2, 4, 6, 9};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;
    
    int rc = solve(matrix1, n, m, &solution);
    ck_assert_int_eq(rc, ERR_SLAE_NO_SOL);
    free_matrix(matrix1, n);
}
END_TEST

// СЛАУ не имет решений
START_TEST(test_slae_inf_sol)
{
    size_t n = 3, m = 4;
    double arr1[] = {78.54, 61.33, -99, 15.4,
                     1, 2, 3, 4,
                     2, 4, 6, 8};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double *solution = NULL;
    
    int rc = solve(matrix1, n, m, &solution);
    ck_assert_int_eq(rc, ERR_SLAE_NO_SOL);
    free_matrix(matrix1, n);
}
END_TEST

Suite* slae_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("slae");
    // Негативы
    TCase *tc_neg = tcase_create("negatives");

    // Добавление в tc_neg функций-тестов
    tcase_add_test(tc_neg, test_slae_inf_sol);
    tcase_add_test(tc_neg, test_slae_no_sol);
    tcase_add_test(tc_neg, test_slae_size);

    // Добавление негативных тестов в набор
    suite_add_tcase(s, tc_neg);

    // Позитивы
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_slae_positives);
    tcase_add_test(tc_pos, test_slae_negatives);
    tcase_add_test(tc_pos, test_slae_different);

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}