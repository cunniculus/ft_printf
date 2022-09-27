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
	expected_int[2] = 12;
	expected_int[3] = 15;
	expected_int[4] = 34;
	expected_int[5] = 15;
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

MU_TEST(test_print_percentage) 
{
	result_int[2] = ft_printf("%%%c%s\n", 'P', "ercentage");
	mu_assert_int_eq(expected_int[2], result_int[2]);
}
MU_TEST(test_print_int) 
{
	result_int[3] = ft_printf("%d %i%s\n", 42, 37, " anthopos");
	mu_assert_int_eq(expected_int[3], result_int[3]);
}

MU_TEST(test_print_uint) 
{
	result_int[4] = ft_printf("Largest unsigned int: %u!\n", INT_MAX + (-1) * INT_MIN);
	mu_assert_int_eq(expected_int[4], result_int[4]);
}

MU_TEST(test_print_pointer) 
{
	printf("%p\n", result_int);
	result_int[5] = ft_printf("%p\n", result_int);
	mu_assert_int_eq(15, result_int[5]);
}

MU_TEST_SUITE(mandatorio) // static void test_suit_1(void)
{
	MU_SUITE_CONFIGURE(&test_setup_1, &test_teardown_1); 

	MU_RUN_TEST(test_print_char);
	MU_RUN_TEST(test_print_str); 
	MU_RUN_TEST(test_print_percentage);
	MU_RUN_TEST(test_print_int);
	MU_RUN_TEST(test_print_uint);
	MU_RUN_TEST(test_print_pointer);
}

// --- Tests for bonus part --- 

void test_setup_bonus(void) // setup at the start of a test suit
{
	expected_int[0] = 4;
	expected_int[1] = 11;
	expected_int[2] = 2;
	expected_int[3] = 11;
	expected_int[4] = 4;
	expected_int[5] = 11;
	expected_int[6] = 4;
	expected_int[7] = 10;
	expected_int[8] = 10;
	expected_int[9] = 8;
	expected_int[10] = 14;
	expected_int[11] = 14;
	expected_int[12] = 16;
	expected_int[13] = 14;
	expected_int[14] = 16;

}

void test_teardown_bonus(void) // closing down at the end of a test suit
{
	/* Nothing */
}
MU_TEST(test_alt) 
{
	result_int[0] = ft_printf("%#x\n", 10);
	mu_assert_int_eq(expected_int[0], result_int[0]);
	result_int[1] = ft_printf("%#x\n", 2147483647);
	mu_assert_int_eq(expected_int[1], result_int[1]);
	result_int[2] = ft_printf("%#x\n", 0);
	mu_assert_int_eq(expected_int[2], result_int[2]);
	result_int[3] = ft_printf("%#x\n", -1);
	mu_assert_int_eq(expected_int[3], result_int[3]);
	result_int[4] = ft_printf("%#X\n", 10);
	mu_assert_int_eq(expected_int[4], result_int[4]);
	result_int[5] = ft_printf("%#X\n", UINT_MAX);
	mu_assert_int_eq(expected_int[5], result_int[5]);
	result_int[6] = ft_printf("%#o\n", 10);
	mu_assert_int_eq(expected_int[6], result_int[6]);
}
MU_TEST(test_space)
{
	result_int[7] = ft_printf("% d |% i\n", 10, 234);
	mu_assert_int_eq(expected_int[7], result_int[7]);
	result_int[8] = ft_printf("% d |% i\n", -10, -234);
	mu_assert_int_eq(expected_int[8], result_int[8]);
}
MU_TEST(test_width)
{
	result_int[9] = ft_printf("%2d |%3i\n", 1, -1);
	mu_assert_int_eq(expected_int[9], result_int[9]);
	result_int[10] = ft_printf("%5d |%6i\n", 1, -1);
	mu_assert_int_eq(expected_int[10], result_int[10]);
	result_int[11] = ft_printf("%+5d |%+6i\n", 1, -1);
	mu_assert_int_eq(expected_int[11], result_int[11]);
	result_int[12] = ft_printf("%+6d |%+7i\n", 2345, -3456);
	mu_assert_int_eq(expected_int[12], result_int[12]);
	result_int[13] = ft_printf("% 5d |% 6i\n", 1, -1);
	mu_assert_int_eq(expected_int[13], result_int[13]);
	result_int[14] = ft_printf("% 6d |% 7i\n", 2345, -3456);
	mu_assert_int_eq(expected_int[14], result_int[14]);

}
MU_TEST_SUITE(bonus) 
{
	MU_SUITE_CONFIGURE(&test_setup_bonus, &test_teardown_bonus); 

	MU_RUN_TEST(test_alt);
	MU_RUN_TEST(test_space);
	MU_RUN_TEST(test_width);
}

int main(void) 
{
	MU_RUN_SUITE(mandatorio);
	MU_RUN_SUITE(bonus);
	MU_REPORT();
	return MU_EXIT_CODE; // exit conde = minunit_fail 
}
