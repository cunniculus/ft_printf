/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:08:13 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 01:53:51 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	convert_u(t_printf_info *info, va_list args)
{
	char			*str_nbr;
	size_t			counter;
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	counter = 0;
	if (!nbr && !info->prec)
	{
		if (info->width)
		{
			str_nbr = ft_strdup("");
			str_nbr = get_width(info, &str_nbr);
			counter += ft_putstr_fd(str_nbr, 1);
			free(str_nbr);
		}
		return (counter);
	}
	str_nbr = ft_utoa(nbr);
	str_nbr = get_precision_diu(info, &str_nbr);
	str_nbr = get_width(info, &str_nbr);
	counter += ft_putstr_fd(str_nbr, 1);
	free(str_nbr);
	return (counter);
}

size_t	convert_di(t_printf_info *info, va_list args)
{
	char	*str_nbr;
	size_t	counter;
	int		nbr;

	nbr = va_arg(args, int);
	counter = 0;
	if (!nbr && !info->prec)
	{
		if (info->width)
		{
			str_nbr = ft_strdup("");
			str_nbr = get_width(info, &str_nbr);
			counter += ft_putstr_fd(str_nbr, 1);
			free(str_nbr);
		}
		return (counter);
	}
	str_nbr = ft_itoa(nbr);
	str_nbr = get_precision_diu(info, &str_nbr);
	str_nbr = get_width(info, &str_nbr);
	counter += ft_putstr_fd(str_nbr, 1);
	free(str_nbr);
	return (counter);
}
