#include "libftprintf.h"

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
	if (info->spec == 'u')
		return (convert_u(info, args));
	if (info->spec == 'd' || info->spec == 'i')
		return (convert_di(info, args));
	return (0);
}

int	convert_pchar(t_printf_info *info, va_list args)
{
	if (info->spec == '%' || info->spec == 'c')
		return (convert_c_and_percent(info, args));
	if (info->spec == 's')
		return (convert_s(info, args));
	if (info->spec == 'p')
		return (convert_p(info, args));
	return (0);
}

int	convert_base(t_printf_info *info, va_list args)
{
	unsigned	nbr;
	char		*str;
	size_t		counter;
	int			len;
	int			max_len;

	counter = 0;
	len = 0;
	if (info->spec == 'o')
	{
		nbr = va_arg(args, unsigned int);
		str = ft_litoa_base(nbr, OCTALBASE);
		if (info->alt)
			if (nbr)
				str = ft_strjoin_free("0", &str);
		len = (int) ft_strlen(str);
		max_len = max_length(info->prec, len);
		while (info->width > max_len)
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		while (info->prec > len)
		{
			counter += ft_putchar_fd('0', 1);
			info->prec--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
	if (info->spec == 'x')
	{
		nbr = va_arg(args, unsigned int);
		str = ft_litoa_base(nbr, HEXBASELOW);
		
		if (info->prec)
		{
			len = (int) ft_strlen(str);
			while (info->prec > len)
			{
				str = ft_strjoin_free("0", &str);
				info->prec--;
			}
			counter += ft_putstr_fd("0x", 1);
			counter += ft_putstr_fd(str, 1);
			return (counter);
		}

		if (info->alt && nbr)
		{
			if (!info->prec && !(info->width >= 0 && info->pad == '0'))
				str = ft_strjoin_free("0x", &str);
		}
		len = (int) ft_strlen(str);
		while (info->width > len)
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
		
		if (info->prec)
		{
			len = (int) ft_strlen(str);
			while (info->prec > len)
			{
				str = ft_strjoin_free("0", &str);
				info->prec--;
			}
			if (info-alt && nbr)
				str ft_strjoin_free("0X", &str);
			counter += ft_putstr_fd(str, 1);
		}
		if (info->width)
		{

			if (info->alt && nbr)
			{
			counter += ft_putstr_fd("0X", 1);
		}
		len = (int) ft_strlen(str);
		while (info->width > len)
		{
			counter += ft_putchar_fd(info->pad, 1);
			info->width--;
		}
		counter += ft_putstr_fd(str, 1);
		free (str);
	}
		return (counter);
}
