#include <unistd.h> //open() close ()
#include <stdlib.h> // free()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "libftprintf.h"
#include "minunit.h"

static int iexpected = 0;
static int iresult= 0;
//static double dbar = 0.1;
static const char* sexpected;
static const char* sresult;

void test_setup_1(void) // setup at the start of a test suit
{
	iexpected = 42;
}

void test_teardown_1(void) // closing down at the end of a test suit
{
	/* Nothing */
}

MU_TEST(test_name_1) // static void test_name_1(void)
{
	// ARRANGE
	iresult = 42;
	

	// ACT

	// ASSERT
		mu_assert_string_eq(sexpected, sresult);
			// increment minunit_assert
			// if (expected != result){ print fail msg with message; minunit_status = 1 } 
			// else print ok
		mu_check(1 == 1);
			// increment minunit_assert
			// if (!test){ print fail msg; minunit_status = 1 } 
			// else print ok
		if (0)
		{
			mu_fail("Fail");
				// increment minunit_assert
				// print message
				// minunit_status = 1;
		}
		mu_assert(1 == 1, "Fail");
			// increment minunit_assert
			// if (!test){ print fail msg with message; minunit_status = 1 } 
			// else print ok
		mu_assert_int_eq(iexpected, iresult);
			// increment minunit_assert
			// if (expected != result){ print fail msg with message; minunit_status = 1 } 
			// else print ok
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
