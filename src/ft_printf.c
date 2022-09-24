#include "libftprintf.h"

// TODO 
	// convert specifier c
	// convert specifier s
	// convert specifier p
	// convert specifier d
	// convert specifier i
	// convert specifier u
	// convert specifier x
	// convert specifier X
	// convert specifier %
	// flags
		// -
		// 0
		// .
		// #
		// ' '
		// +
	// minimum field width

	// if % calls converts; else calls putchar
static int	parce_format(const char **format, va_list args, size_t *counter);
static int	converter(const char **format, va_list args, size_t *counter);
	// initialize flag_set to nul char; returns void
static void	nul_init(char flag_set[FLAG_SIZE]);
	// boolean function
static int	char_is_flag(int c);
	// boolean function
static int	char_is_specifier(char c);
 // flag_grabber: grabs flag, minimal width, and precision from format string, 
 // stores it on flag_set, and updates format pointer position
 // returns numbers of flags on the current conversiont specification
static int	flag_grabber(const char **format, char flag_set[FLAG_SIZE]);
static int	convert_print(const char **format, va_list args,\
		size_t *counter, char flag_set[FLAG_SIZE]);

int	ft_printf(const char *format, ...)
{
	va_list args; // declares list of arguments object
	size_t	printed_char_counter;

	va_start(args, format); // start list of arguments
	printed_char_counter = 0;
	parce_format(&format, args, &printed_char_counter); // start format string parsing
	va_end(args); // end list of arguments
	return (printed_char_counter);
}

static int	parce_format(const char **format, va_list args, size_t *counter)
{
	while (**format)
	{
		if (**format == '%') // conversion specification
		{
			(*format)++;
			converter(format, args, counter); // start conversion analysis
		}
		else
		{
			ft_putchar_fd(**format, 1);
			(*counter)++;
		}
		(*format)++;
	}
	return (0);
}

static int	converter(const char **format, va_list args, size_t *counter)
{
	char flag_set[FLAG_SIZE];

	nul_init(flag_set);
	if (char_is_flag(**format))
		flag_grabber(format, flag_set);
	if (char_is_specifier(**format))
		convert_print(format, args, counter, flag_set);
	return (0);	
}

static int	flag_grabber(const char **format, char flag_set[FLAG_SIZE])
{
	int	i;

	i = 0;
	while (char_is_flag(**format))
	{
		flag_set[i] = **format;
		(*format)++;
		i++;
	}
	return (i);
}

static int	convert_print(const char **format, va_list args,\
		size_t *counter, char flag_set[FLAG_SIZE])
{
	if (**format == 'c')
		(*counter) += ft_putchar_fd(va_arg(args, unsigned int), 1);
	if (**format == 's')
		(*counter) += ft_putstr_fd(va_arg(args, char *), 1);
	if (flag_set)
	{
		;
	}
	return (*counter);
}

static void	nul_init(char flag_set[FLAG_SIZE])
{
	int	i;

	i = 0;
	while (flag_set[i])
	{
		flag_set[i] = '\0';
		i++;
	}
}

static int	char_is_flag(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+'\
			|| c == '.' || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}

static int char_is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||\
		c == 'x' || c == 'X')
		return (TRUE);
	return (FALSE);
}

