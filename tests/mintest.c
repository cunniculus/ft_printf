#include <unistd.h> //open() close ()
#include <stdlib.h> // free()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "libftprintf.h"
#include "minunit.h"

#define SIZE 10

static unsigned int expected_int[SIZE];
static unsigned int result_int[SIZE];
//static const char* expected_str;
//static const char* result_str;

void test_setup_1(void) // setup at the start of a test suit
{
	expected_int[0] = 4;
	expected_int[1] = 20;
}

void test_teardown_1(void) // closing down at the end of a test suit
{
	/* Nothing */
}

MU_TEST(test_print_char) 
{
	result_int[0] = ft_printf("%c%c%c\n", 'G', 'U', 'I');
	mu_assert_int_eq(expected_int[0], result_int[0]);
}
MU_TEST(test_print_str) 
{
	result_int[1] = ft_printf("%s%s%s\n", "Gui", " Coelho", " Oliveira");
	mu_assert_int_eq(expected_int[1], result_int[1]);
}

MU_TEST_SUITE(test_suite_1) // static void test_suit_1(void)
{
	MU_SUITE_CONFIGURE(&test_setup_1, &test_teardown_1); 

	MU_RUN_TEST(test_print_char);
	MU_RUN_TEST(test_print_str); 
}

int main(void) 
{
	MU_RUN_SUITE(test_suite_1);
	MU_REPORT();
	return MU_EXIT_CODE; // exit conde = minunit_fail 
}
