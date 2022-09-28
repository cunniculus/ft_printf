#include "libftprintf.h"

size_t	convert_u(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;

	counter = 0;
	if (info->spec == 'u')
	{
		str_nbr = ft_utoa(va_arg(args, unsigned int));
		counter += width_and_precision_handler(info, str_nbr);
		counter += ft_putstr_fd(str_nbr, 1);
		free(str_nbr);
	}
	return (counter);
}

size_t convert_di(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;
	int		i;

	counter = 0;
	str_nbr = ft_itoa(va_arg(args, int)); 
	if (info->showsign && !(*str_nbr == '-'))
		str_nbr = ft_strjoin_free("+", &str_nbr);
	else if (info->space && !(*str_nbr == '-'))
		str_nbr = ft_strjoin_free(" ", &str_nbr);
	i = 0;
	if ((info->pad == '0' || info->prec) && *str_nbr == '-')
	{
		counter += ft_putchar_fd('-', 1);
		i++;
	}
	counter += width_and_precision_handler(info, str_nbr);
	counter += ft_putstr_fd(&str_nbr[i], 1);
	free(str_nbr);
	return (counter);
}

size_t	width_and_precision_handler(t_printf_info *info, char *str)
{
	int	len;
	int max_len;
	size_t	counter;

	len = (int) ft_strlen(str);
	max_len = max_length(info->prec, len);
	counter = 0;
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
	return counter;
}

int	max_length(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

