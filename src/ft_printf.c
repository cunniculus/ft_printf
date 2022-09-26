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
static int setup_ftprintf_info(const char **format, size_t *counter, t_printf_info *info);
	// initialize flag_set to nul char; returns void
static void	nul_init(char flag_set[FLAG_SIZE]);
	// boolean function
static int	char_is_flag(int c);
	// boolean function
static int	char_is_specifier(char c);
 // flag_grabber: grabs flag, minimal width, and precision from format string, 
 // stores it on flag_set, and updates format pointer position
 // returns numbers of flags on the current conversiont specification
 //
//static int	flag_grabber(const char **format, char flag_set[FLAG_SIZE]);
static int	convert_print(t_printf_info *info, va_list args,\
		size_t *counter, char flag_set[FLAG_SIZE]);
static void	precision_setup(const char **format, t_printf_info *info);
static int	ft_putnbr_base(unsigned int nbr, char *base);

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
	char			flag_set[FLAG_SIZE];
	t_printf_info	info;

	nul_init(flag_set);
	setup_ftprintf_info(format, counter, &info);
	/*
	if (char_is_flag(**format))
		flag_grabber(format, flag_set);
	*/
	convert_print(&info, args, counter, flag_set);
	return (0);	
}

static int setup_ftprintf_info(const char **format, size_t *counter, t_printf_info *info)
{
	while (char_is_flag(**format))
	{
		if (**format == '#')
			info->alt = TRUE;
		if (**format == ' ')
			info->space = TRUE;
		if (ft_isdigit(**format))
		{
		//	width_setup(format, info);
		//	;
		}
		if (**format == '.')
			precision_setup(format, info);
		(*format)++;
	}
	if (char_is_specifier(**format) || **format == '%')
		info->spec = **format;
	return (*counter);
	

}
static void	precision_setup(const char **format, t_printf_info *info)
{
	(*format)++;
	while (ft_isdigit(**format))
	{
		info->prec = info->prec * 10 + **format;
		(*format)++;
	}
	(*format)--;
}

/*
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
*/
static int	convert_print(t_printf_info *info, va_list args,\
		size_t *counter, char flag_set[FLAG_SIZE])
{
	unsigned int_nbr;
	char *str_nbr;

	if (info->spec == 'c')
		(*counter) += ft_putchar_fd(va_arg(args, unsigned int), 1);
	if (info->spec == 's')
		(*counter) += ft_putstr_fd(va_arg(args, char *), 1);
	if (info->spec == 'p')
	{
		; // todo
	}
	if (info->spec == 'd' || info->spec == 'i')
	{
		str_nbr = ft_itoa(va_arg(args, int));
		(*counter) += ft_putstr_fd(str_nbr, 1);
		free(str_nbr);
	}
	if (info->spec == 'u')
	{
		; // todo
	}
	if (info->spec == 'x')
	{
		int_nbr = va_arg(args, int);
		if (info->alt)
			if (int_nbr)
				(*counter) += ft_putstr_fd("0x", 1);
		(*counter) += ft_putnbr_base(int_nbr, HEXBASELOW);
	}
	if (info->spec == 'X')
	{
		; // todo
	}
	if (info->spec == '%')
		(*counter) += ft_putchar_fd('%', 1);
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
	while (i < FLAG_SIZE)
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

static int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	b;
	int				digit;
	char			nbr_to_print[11];
	unsigned int	nbr_cpy;

	nbr_cpy = nbr;
	b = ft_strlen(base);
	digit = 1;
	while (nbr_cpy >= b)
	{
		nbr_cpy /= b;
		digit++;
	}
	nbr_to_print[digit] = '\0';
	if (!nbr)
		nbr_to_print[0] = '0';
	while (nbr)
	{
		digit--;
		nbr_to_print[digit] = base[nbr % b];
		nbr = nbr / b;
	}
	ft_putstr_fd(nbr_to_print, 1);
	return (ft_strlen(nbr_to_print));
}
