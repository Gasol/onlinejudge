#include<stdio.h>
#include<stdlib.h>
#include<check.h>
#include"../src/a100.h"

START_TEST (test_cycle_count)
{
	fail_unless(cycle_count(22) == 16, NULL);
}
END_TEST

START_TEST (test_max_cycle)
{
	fail_unless(max_cycle(1, 10) == 20, NULL);
	fail_unless(max_cycle(100, 200) == 125, NULL);
	fail_unless(max_cycle(201, 210) == 89, NULL);
	fail_unless(max_cycle(900, 1000) == 174, NULL);
	fail_unless(max_cycle(1000, 900) == 174, NULL);
}
END_TEST

Suite* a100_suite (void)
{
	Suite *s = suite_create ("a100");

	TCase *tc_core = tcase_create ("100 - The 3n + 1 problem");
	tcase_add_test (tc_core, test_cycle_count);
	tcase_add_test (tc_core, test_max_cycle);
	suite_add_tcase (s, tc_core);

	return s;
}

int main(int argc, char *argv[])
{
	int num_failed = 0;
	Suite *s = a100_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	num_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
