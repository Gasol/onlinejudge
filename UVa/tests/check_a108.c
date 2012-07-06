#include<stdio.h>
#include<stdlib.h>
#include<check.h>
#include"../src/a108.h"

START_TEST (test_max_sum)
{
	int array1[] = {0, -2, -7, 0, 9, 2, -6, 2, -4, 1, -4, 1, -1, 8, 0, -2};
    fail_unless(max_sum(array1, 4) == 15, NULL);

	int array2[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16};
    fail_unless(max_sum(array2, 4) == -1, NULL);

	int array3[] = {1, -61, 5126, 612, 6, 41, 6, 7, 2, -7, 1, 73, -62, 678, 1, 7, -616136,
	   	61, -83, 724, -151, 6247, 872, 2517, 8135};
    fail_unless(max_sum(array3, 5) == 18589, NULL);
}
END_TEST

Suite* a108_suite (void)
{
    Suite *s = suite_create ("a108");

    TCase *tc_core = tcase_create ("108 - Maximum Sum");
    tcase_add_test (tc_core, test_max_sum);
    suite_add_tcase (s, tc_core);

    return s;
}

int main(int argc, char *argv[])
{
    int num_failed = 0;
    Suite *s = a108_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    num_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
