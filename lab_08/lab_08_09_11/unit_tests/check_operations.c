#include <check.h>
#include <stdlib.h>
#include "inout.h"
#include "operations.h"
#include "check_operations.h"
#include "const.h"

void make_matrix(double arr[], double **matrix, size_t n, size_t m)
{
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = arr[count++];
        }
    }
}

// Сложение
// Позитивные тесты

// Cложение матриц с положительными числами
START_TEST(test_adding_positives)
{
    size_t n = 3, m = 4;
    //Матрицы для сложения
    double arr1[] = {4.43, 86.55, 4568.22, 9,
                     75, 64, 125.42, 6,
                     7, 506.544, 456, 87};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double arr2[] = {8, 34.11, 6.4324, 87.55,
                         954, 56.443, 34, 8,
                         54, 563, 64.52, 568.222};
    double **matrix2 = allocate_matrix(n, m);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n, m);

    double **res_matrix = allocate_matrix(n, m);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
    }
    ck_assert_ptr_ne(res_matrix, NULL);
    // Ожидаемая матрица
    double expected_arr[] = {12.43, 120.66, 4574.6524, 96.55, 
                             1029, 120.443, 159.42, 14,
                             61, 1069.544, 520.52, 655.222};
    
    int rc = adding(matrix1, n, m, matrix2, n, m, res_matrix);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(res_matrix, n);
}
END_TEST

// Cложение матриц с отрицательными числами
START_TEST(test_adding_negatives)
{
    size_t n = 4, m = 3;
    double arr1[] = {-32.45, -89, -99.99,
                     -78.12322, -487, -88,
                     -444.001, -45.786, -9856,
                     -4501, -78.6448, -12.2222};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double arr2[] = {-999, -312.48, -7,
                     -651.1000, -745.1, -852.001,
                     -58.123, -94.35, -7,
                     -1, -0.024, -249.33};
    double **matrix2 = allocate_matrix(n, m);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n, m);
    
    double **res_matrix = allocate_matrix(n, m);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {-1031.45, -401.48, -106.99,
                             -729.22322, -1232.1, -940.001,
                             -502.124, -140.136, -9863, 
                             -4502, -78.6688, -261.5522 };
    
    int rc = adding(matrix1, n, m, matrix2, n, m, res_matrix);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(res_matrix, n);
}
END_TEST

// Cложение матриц с числами разных знаков
START_TEST(test_adding_different)
{
    size_t n = 3, m = 3;
    double arr1[] = {0, -987, 45.566,
                     20.0002, -77, 0.5489,
                     -461.786, 0, -987.123};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double arr2[] = {-85.1111, 45, 0,
                     32.66, 487.999, -1230,
                     0, 75.159, -492.555};
    double **matrix2 = allocate_matrix(n, m);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n, m);

    double **res_matrix = allocate_matrix(n, m);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {-85.1111, -942, 45.566, 
                             52.6602, 410.999, -1229.451100,
                             -461.786, 75.159, -1479.678000 };
    
    int rc = adding(matrix1, n, m, matrix2, n, m, res_matrix);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(res_matrix, n);
}
END_TEST

// Негативные тесты

// Число строк матриц не равно
START_TEST(test_adding_columns)
{
    size_t n1 = 3, m = 3, n2 = 4;
    double arr1[] = {0, -987, 45.566,
                     20.0002, -77, 0.5489,
                     -461.786, 0, -987.123};
    double **matrix1 = allocate_matrix(n1, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n1, m);

    double arr2[] = {-85.1111, 45, 0,
                     32.66, 487.999, -1230,
                     0, 75.159, -492.555,
                     0, 75.159, -492.555};
    double **matrix2 = allocate_matrix(n2, m);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n1);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n2, m);

    double **res_matrix = allocate_matrix(n1, m);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
    }
    ck_assert_ptr_ne(res_matrix, NULL);
    
    int rc = adding(matrix1, n1, m, matrix2, n2, m, res_matrix);
    ck_assert_int_eq(rc, ERR_ADD);
    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);
    free_matrix(res_matrix, n1);
}
END_TEST

// Число столбцов матриц не равно
START_TEST(test_adding_rows)
{
    size_t n = 3, m1 = 4, m2 = 3;
    double arr1[] = {0, -987, 45.566, 1,
                     20.0002, -77, 0.5489, 1,
                     -461.786, 0, -987.123, 1};
    double **matrix1 = allocate_matrix(n, m1);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m1);

    double arr2[] = {-85.1111, 45, 0,
                     32.66, 487.999, -1230,
                     0, 75.159, -492.555};
    double **matrix2 = allocate_matrix(n, m2);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n, m2);

    double **res_matrix = allocate_matrix(n, m1);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
    }
    ck_assert_ptr_ne(res_matrix, NULL);
    
    int rc = adding(matrix1, n, m1, matrix2, n, m2, res_matrix);
    ck_assert_int_eq(rc, ERR_ADD);
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(res_matrix, n);
}
END_TEST

// Произведение
// Позитивные тесты

// Произведение квадратных матриц
START_TEST(test_mult_squares)
{
    size_t n = 3, m = 3;
    double arr1[] = {0, -987, 45.566,
                     20.0002, -77, 0.5489,
                     -461.786, 0, -987.123};
    double **matrix1 = allocate_matrix(n, m);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n, m);

    double arr2[] = {-85.1111, 45, 0,
                     32.66, 487.999, -1230,
                     0, 75.159, -492.555};
    double **matrix2 = allocate_matrix(n, m);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n, m);

    double **res_matrix = allocate_matrix(n, m);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n);
        free_matrix(matrix2, n);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {-32235.42, -478230.318006, 1191566.23887, 
                             -4217.059022, -36634.659225, 94439.636561,
                             39303.114425, -94971.547557, 486212.369265};
    
    int rc = multiplication(matrix1, n, m, matrix2, n, m, res_matrix);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(res_matrix, n);
}
END_TEST

// Первая марица - строка, вторая - столбец
START_TEST(test_mult_row_column)
{
    size_t n1 = 1, m1 = 5, n2 = 5, m2 = 1;
    double arr1[] = {0, -987, 45.566, -84.23, 32.701};
    double **matrix1 = allocate_matrix(n1, m1);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n1, m1);

    double arr2[] = {-85.1111,
                     32.66,
                     0,
                     496,
                     103.103};
    double **matrix2 = allocate_matrix(n2, m2);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n1);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n2, m2);

    double **res_matrix = allocate_matrix(n1, m2);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {-70641.928797};
    
    int rc = multiplication(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m2 + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);
    free_matrix(res_matrix, n1);
}
END_TEST

// Произведение квадратной и прямоугольной матриц
START_TEST(test_mult_square_rectangle)
{
    size_t n1 = 3, m1 = 3, n2 = 3, m2 = 4;
    double arr1[] = {78.54, 61.33, -99,
                     0, 12.003, -785.11,
                     1.01, -99.36, -456.77};
    double **matrix1 = allocate_matrix(n1, m1);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n1, m1);

    double arr2[] = {86.46, -98.46, 0, -999.999,
                     421, 206.801, -784.564, -487.00007,
                     0, 147, -589.657, 1000.001};
    double **matrix2 = allocate_matrix(n2, m2);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n1);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n2, m2);

    double **res_matrix = allocate_matrix(n1, m2);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {32610.4984, -9602.94307, 10258.73288, -207407.734753,
                             5053.263000, -112928.937597, 453528.485578, -790956.246950,
                             -41743.235400, -87792.381960, 347291.906930, -409392.128805};
    
    int rc = multiplication(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m2 + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);
    free_matrix(res_matrix, n1);
}
END_TEST

// Произведение прямоугольных матриц
START_TEST(test_mult_rectangles)
{
    size_t n1 = 4, m1 = 3, n2 = 3, m2 = 4;
    double arr1[] = {78.54, 61.33, -99,
                     0, 12.003, -785.11,
                     1.01, -99.36, -456.77,
                     -89.55, 431, 678.003};
    double **matrix1 = allocate_matrix(n1, m1);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n1, m1);

    double arr2[] = {86.46, -98.46, 0, -999.999,
                     421, 206.801, -784.564, -487.00007,
                     0, 147, -589.657, 1000.001};
    double **matrix2 = allocate_matrix(n2, m2);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n1);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n2, m2);

    double **res_matrix = allocate_matrix(n1, m2);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
    }
    ck_assert_ptr_ne(res_matrix, NULL);

    double expected_arr[] = {32610.4984, -9602.94307, 10258.73288, -207407.734753,
                             5053.263000, -112928.937597, 453528.485578, -790956.246950,
                             -41743.235400, -87792.381960, 347291.906930, -409392.128805,
                             173708.507, 197614.765, -737936.298971, 557656.558283};
    
    int rc = multiplication(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            ck_assert_double_eq_tol(res_matrix[i][j], expected_arr[i * m2 + j], 1e-6);
        }
    }
    ck_assert_int_eq(rc, 0);
    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);
    free_matrix(res_matrix, n1);
}
END_TEST

// Негативы

// Неподходящие размеры матриц для умножения
START_TEST(test_mult_sizes)
{
    size_t n1 = 4, m1 = 3, n2 = 2, m2 = 4;
    double arr1[] = {78.54, 61.33, -99,
                     0, 12.003, -785.11,
                     1.01, -99.36, -456.77,
                     -89.55, 431, 678.003};
    double **matrix1 = allocate_matrix(n1, m1);
    ck_assert_ptr_ne(matrix1, NULL);
    make_matrix(arr1, matrix1, n1, m1);

    double arr2[] = {86.46, -98.46, 0, -999.999,
                     421, 206.801, -784.564, -487.00007};
    double **matrix2 = allocate_matrix(n2, m2);
    if (matrix2 == NULL)
    {
        free_matrix(matrix1, n1);
    }
    ck_assert_ptr_ne(matrix2, NULL);
    make_matrix(arr2, matrix2, n2, m2);

    double **res_matrix = allocate_matrix(n1, m2);
    if (res_matrix == NULL)
    {
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
    }
    ck_assert_ptr_ne(res_matrix, NULL);
    
    int rc = multiplication(matrix1, n1, m1, matrix2, n2, m2, res_matrix);
    ck_assert_int_eq(rc, ERR_MULT);
    free_matrix(matrix1, n1);
    free_matrix(matrix2, n2);
    free_matrix(res_matrix, n1);
}
END_TEST

Suite* operations_suite(void)
{
    // Создание тестового набора
    Suite *s = suite_create("operations");
    // Негативы
    TCase *tc_neg = tcase_create("negatives");

    // Добавление в tc_neg функций-тестов
    tcase_add_test(tc_neg, test_adding_columns);
    tcase_add_test(tc_neg, test_adding_rows);
    tcase_add_test(tc_neg, test_mult_sizes);

    // Добавление негативных тестов в набор
    suite_add_tcase(s, tc_neg);

    // Позитивы
    TCase *tc_pos = tcase_create("positives");

    // Добавление в tc_pos функций-тестов
    tcase_add_test(tc_pos, test_adding_positives);
    tcase_add_test(tc_pos, test_adding_negatives);
    tcase_add_test(tc_pos, test_adding_different);
    tcase_add_test(tc_pos, test_mult_rectangles);
    tcase_add_test(tc_pos, test_mult_square_rectangle);
    tcase_add_test(tc_pos, test_mult_squares);
    tcase_add_test(tc_pos, test_mult_row_column);

    // Добавление позитивных тестов в набор
    suite_add_tcase(s, tc_pos);
    return s;
}