#include <unistd.h> //open() close ()
#include <stdlib.h> // free()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "get_next_line.h"
#include "minunit.h"

static int foo = 0;
static int bar = 0;
static int  fd;
//static double dbar = 0.1;
//static const char* foostring = "Thisstring";

void test_setup_1(void) // setup at the start of a test suit
{
	foo = 7;
	bar = 4;
}

void test_teardown_1(void) // closing down at the end of a test suit
{
	/* Nothing */
}

MU_TEST(test_name_1) // static void test_name_1(void)
{
	// ARRANGE
	

	// ACT

	// ASSERT
		mu_assert_string_eq(actual_return, expected_return);
		mu_check(test);
			// increment minunit_assert
			// 
}

MU_TEST_SUITE(test_suite_1) // static void test_suit_1(void)
{
	MU_SUITE_CONFIGURE(&test_setup_1, &test_teardown_1); 
		// minunit_setup = test_setup_1;
		// minunit_teardown = teardown_1;

	MU_RUN_TEST(test_name_1);
		// runs minunit_setup
		// runs test and increment minunit_run. 
		// if fails (minunit_status), increment minunit_fail and prints fail
		// runs minunit_teardown
}

int main(void) 
{
	MU_RUN_SUITE(test_suite_1);
	MU_REPORT();
		// print minunit_run, minunit_assert, minunit_fail
		// print timer
	return MU_EXIT_CODE; // exit conde = minunit_fail 
}
