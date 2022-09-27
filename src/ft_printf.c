#include "libftprintf.h"
	
	// if % calls converts; else calls putchar
static int	parce_format(const char **format, va_list args, size_t *counter);
static int	converter(const char **format, va_list args, size_t *counter);
static int	setup_specification_info(const char **format, size_t *counter,\
		t_printf_info *info);
static void	precision_setup(const char **format, t_printf_info *info);
static void	width_setup(const char **format, t_printf_info *info);
static void init_specification_info(t_printf_info *info);

int	ft_printf(const char *format, ...)
{
	va_list args;
	size_t	printed_char_counter;

	va_start(args, format);
	printed_char_counter = 0;
	parce_format(&format, args, &printed_char_counter); // start format string parsing
	va_end(args);
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
	return (*counter);
}

static int	converter(const char **format, va_list args, size_t *counter)
{
	t_printf_info	info;

	init_specification_info(&info);
	setup_specification_info(format, counter, &info);
	convert_printf(&info, args, counter);
	return (0);	
}

static int setup_specification_info(const char **format, size_t *counter,\
		t_printf_info *info)
{
	while (char_is_flag(**format))
	{
		if (**format == '#')
			info->alt = TRUE;
		if (**format == ' ')
			info->space = TRUE;
		if (**format == '-')
			info->left = TRUE;
		if (**format == '+')
			info->showsign = TRUE;
		if (**format == '0')
			info->pad = '0';
		(*format)++;
	}
	if (ft_isdigit(**format))
		width_setup(format, info);
	if (**format == '.')
		precision_setup(format, info);
	if (char_is_specifier(**format) || **format == '%')
		info->spec = **format;
	return (*counter);
}

static void	width_setup(const char **format, t_printf_info *info)
{
	info->width = 0;
	while (ft_isdigit(**format))
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	precision_setup(const char **format, t_printf_info *info)
{
	(*format)++;
	while (ft_isdigit(**format))
	{
		info->prec = info->prec * 10 + (**format - '0');
		(*format)++;
	}
}

static void init_specification_info(t_printf_info *info)
{
	info->alt = FALSE;
	info->space = FALSE;
	info->left = FALSE;
	info->showsign = FALSE;
	info->pad = ' ';
	info->width = -1;
	info->prec = 0;
	info->spec = '\0';
}
