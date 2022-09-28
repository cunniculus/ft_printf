/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:08:13 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/28 23:09:27 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	convert_u(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;

	counter = 0;
	if (info->spec == 'u')
	{
		str_nbr = ft_utoa(va_arg(args, unsigned int));
		str_nbr = get_precision_diu(info, &str_nbr);
		str_nbr = get_width(info, &str_nbr);
		counter += ft_putstr_fd(str_nbr, 1);
		free(str_nbr);
	}
	return (counter);
}

size_t	convert_di(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;

	counter = 0;
	str_nbr = ft_itoa(va_arg(args, int));
	str_nbr = get_precision_diu(info, &str_nbr);
	str_nbr = get_width(info, &str_nbr);
	counter += ft_putstr_fd(str_nbr, 1);
	free(str_nbr);
	return (counter);
}

size_t	width_and_precision_handler(t_printf_info *info, char *str)
{
	size_t	len;
	size_t	counter;

	len = ft_strlen(str);
	counter = 0;
	while (info->width - info->prec > (int) len)
	{
		counter += ft_putchar_fd(info->pad, 1);
		info->width--;
	}
	while (info->prec > (int) len)
	{
		counter += ft_putchar_fd('0', 1);
		info->prec--;
	}
	return (counter);
}
