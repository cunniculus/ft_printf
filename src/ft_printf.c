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
static int	parce_format(const char *str);
static int	converter(const char *format);
static int	char_is_flag(int c);
static int	flag_handler(const char *format);

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	va_end(args);
	parce_format(format);
	return (0);
}

static int	parce_format(const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			converter(format);
			// do something cool
		}
		else
		{
			// print
			;
		}

	}
	return (0);
}

static int	converter(const char *format)
{
	if (char_is_flag(*format))
	{
		flag_handler(format);
	}

	return (0);	
}

static int	char_is_flag(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}

static int	flag_handler(const char *format)
{
	if (*format)
	{
		;
	}
	return (0);

}
