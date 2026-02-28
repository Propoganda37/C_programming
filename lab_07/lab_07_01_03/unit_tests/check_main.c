#include <check.h>
#include <stdlib.h>
#include "check_sort.h"
#include "check_filter.h"

int main(void)
{
    int no_failed = 0;
    Suite *s = sort_suite(), *f = filter_suite();
    // Создание "runner"
    SRunner *runner = srunner_create(s);
    srunner_add_suite(runner, f);

    // Запуск всех тестов
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}