/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_and_str_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:05:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/29 20:20:36 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

size_t	convert_c_and_percent(t_printf_info *info, va_list args)
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

size_t	convert_s(t_printf_info *info, va_list args)
{
	size_t	counter;
	char	*str;
	char	*tmp;

	counter = 0;
	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	tmp = str;
	if (info->prec >= 0)
	{
		str = get_precision_s(info, &str);
		if (*str == '-')
			free(tmp);
	}
	if (info->width >= 0)
		str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free(str);
	return (counter);
}
