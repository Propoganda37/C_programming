#include <check.h>
#include <stdlib.h>
#include "check_item_arr.h"

int main(void)
{
    int no_failed = 0;
    Suite *i = item_arr_suite();
    // Создание "runner"
    SRunner *runner = srunner_create(i);

    // Запуск всех тестов
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}