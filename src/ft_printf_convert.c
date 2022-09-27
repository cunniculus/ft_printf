#include "libftprintf.h"
#include <stdio.h>

int	convert_printf(t_printf_info *info, va_list args, size_t *counter)
{
	(*counter) += convert_nbr_int(info, args);
	convert_pchar(info, args, counter);
	convert_base(info, args, counter);
	return (*counter);
}

size_t	convert_nbr_int(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;

	counter = 0;
	if (info->spec == 'd' || info->spec == 'i')
	{
		str_nbr = ft_itoa(va_arg(args, int));
		// printf("%d %zu\n", info->width, ft_strlen(str_nbr));
		if (info->showsign && !(*str_nbr == '-'))
			str_nbr = ft_strjoin_free("+", &str_nbr);
		else if (info->space && !(*str_nbr == '-'))
			str_nbr = ft_strjoin_free(" ", &str_nbr);
		while (info->width-- > (int) ft_strlen(str_nbr))
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putstr_fd(str_nbr, 1);
		free(str_nbr);
	}
	if (info->spec == 'u')
	{
		counter += ft_putnbr_base(va_arg(args, unsigned int), DECIMALBASE);
	}
	return (counter);
}

int	convert_pchar(t_printf_info *info, va_list args, size_t *counter)
{
	if (info->spec == '%')
		(*counter) += ft_putchar_fd('%', 1);
	if (info->spec == 'c')
		(*counter) += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	if (info->spec == 's')
		(*counter) += ft_putstr_fd(va_arg(args, char *), 1);
	if (info->spec == 'p')
	{
		(*counter) += ft_putstr_fd("0x", 1);
		(*counter) += ft_putnbr_base(va_arg(args, unsigned long int), HEXBASELOW);
	}
	return (*counter);
}

int	convert_base(t_printf_info *info, va_list args, size_t *counter)
{
	unsigned int_nbr;

	if (info->spec == 'o')
	{
		int_nbr = va_arg(args, unsigned int);
		if (info->alt)
			if (int_nbr)
				(*counter) += ft_putchar_fd('0', 1);
		(*counter) += ft_putnbr_base(int_nbr, OCTALBASE);
	}
	if (info->spec == 'x')
	{
		int_nbr = va_arg(args, unsigned int);
		if (info->alt)
			if (int_nbr)
				(*counter) += ft_putstr_fd("0x", 1);
		(*counter) += ft_putnbr_base(int_nbr, HEXBASELOW);
	}
	if (info->spec == 'X')
	{
		int_nbr = va_arg(args, unsigned int);
		if (info->alt)
			if (int_nbr)
				(*counter) += ft_putstr_fd("0X", 1);
		(*counter) += ft_putnbr_base(int_nbr, HEXBASEUP);
	}
	return (*counter);
}
