#include <check.h>
#include <stdlib.h>
#include "check_operations.h"
#include "check_slae.h"

int main(void)
{
    int no_failed = 0;
    Suite *s = slae_suite(), *o = operations_suite();
    // Создание "runner"
    SRunner *runner = srunner_create(o);
    srunner_add_suite(runner, s);

    // Запуск всех тестов
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}