#include "libftprintf.h"
#include <stdio.h>

int	convert_printf(t_printf_info *info, va_list args, size_t *counter)
{
	size_t	conv;

	conv = convert_nbr_int(info, args);
	if (conv)
	{
		(*counter) += conv;
		return (*counter);
	}
	conv = (convert_pchar(info, args));
	if (conv)
	{
		(*counter) += conv;
		return (*counter);
	}
	conv = convert_base(info, args);
	if (conv)
	{
		(*counter) += conv;
		return (*counter);
	}
	return (*counter);
}

size_t	convert_nbr_int(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;
	int		i;

	counter = 0;
	if (info->spec == 'd' || info->spec == 'i')
	{
		
		str_nbr = ft_itoa(va_arg(args, int)); 
		if (info->showsign && !(*str_nbr == '-'))
			str_nbr = ft_strjoin_free("+", &str_nbr);
		else if (info->space && !(*str_nbr == '-'))
			str_nbr = ft_strjoin_free(" ", &str_nbr);
		i = 0;
		if (info->pad == '0' && *str_nbr == '-')
		{
			counter += ft_putchar_fd('-', 1);
			i++;
		}
		while (info->width-- > (int) ft_strlen(str_nbr))
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putstr_fd(&str_nbr[i], 1);
		free(str_nbr);
	}
	if (info->spec == 'u')
	{
		str_nbr = ft_utoa(va_arg(args, unsigned int));
		i = 0;
		if (info->pad == '0' && *str_nbr == '-')
		{
			counter += ft_putchar_fd('-', 1);
			i++;
		}
		while (info->width-- > (int) ft_strlen(str_nbr))
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putstr_fd(&str_nbr[i], 1);
		free(str_nbr);
	}
	return (counter);
}

int	convert_pchar(t_printf_info *info, va_list args)
{
	size_t				counter;
	int					i;
	char				*str;
	unsigned long int	hex_nbr;

	counter = 0;
	if (info->spec == '%')
		counter += ft_putchar_fd('%', 1);
	if (info->spec == 'c')
	{
		while (info->width-- > 1) 
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	}
	if (info->spec == 's')
	{
		str = va_arg(args, char *);
		while (info->width > (int) ft_strlen(str)) 
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		i = 0;
		while (i < info->width)
		{
			counter += ft_putchar_fd(str[i], 1);
			i++;
		}
		if (info->width == -1)
			counter += ft_putstr_fd(str, 1);
	}
	if (info->spec == 'p')
	{
		hex_nbr = va_arg(args, unsigned long int);
		str = ft_litoa_base(hex_nbr, HEXBASELOW);
		str = ft_strjoin_free("0x", &str);
		while (info->width > (int) ft_strlen(str)) 
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
	return (counter);
}

int	convert_base(t_printf_info *info, va_list args)
{
	unsigned	nbr;
	char		*str;
	size_t		counter;

	counter = 0;
	if (info->spec == 'o')
	{
		nbr = va_arg(args, unsigned int);
		str = ft_litoa_base(nbr, OCTALBASE);
		if (info->alt)
			if (nbr)
				str = ft_strjoin_free("0", &str);
		while (info->width > (int) ft_strlen(str)) 
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
	if (info->spec == 'x')
	{
		nbr = va_arg(args, unsigned int);
		str = ft_litoa_base(nbr, HEXBASELOW);
		if (info->alt)
			if (nbr)
				str = ft_strjoin_free("0x", &str);
		while (info->width > (int) ft_strlen(str)) 
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
	if (info->spec == 'X')
	{
		nbr = va_arg(args, unsigned int);
		str = ft_litoa_base(nbr, HEXBASEUP);
		if (info->alt)
			if (nbr)
				str = ft_strjoin_free("0X", &str);
		while (info->width > (int) ft_strlen(str)) 
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
	return (counter);
}
