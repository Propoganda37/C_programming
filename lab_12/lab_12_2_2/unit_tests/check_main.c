#include <check.h>
#include <stdlib.h>
#include "check_insert.h"
#include "check_prime.h"

int main(void)
{
    int no_failed = 0;
    Suite *p = prime_suite(), *i = insert_suite();
    SRunner *runner = srunner_create(p);
    srunner_add_suite(runner, i);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}