#include "libftprintf.h"

size_t convert_c_and_percent(t_printf_info *info, va_list args)
{
	size_t				counter;

	counter = 0;
	if (info->spec == '%')
		counter += ft_putchar_fd('%', 1);
	if (info->spec == 'c')
	{
		while (info->width-- > 1) 
			counter += ft_putchar_fd(info->pad, 1);
		counter += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	}
	return (counter);
}

size_t convert_s(t_printf_info *info, va_list args)
{
	size_t	counter;
	char	*str;
	int		i;

	str = va_arg(args, char *);
	counter = 0;
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
	return (counter);
}


