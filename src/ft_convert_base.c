/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:20:10 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 01:53:16 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	convert_o(t_printf_info *info, va_list args)
{
	unsigned int	nbr;
	char			*str;
	size_t			counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	str = ft_litoa_base(nbr, OCTALBASE);
	str = get_precision_base(info, &str);
	if (info->alt && nbr)
		str = ft_strjoin_free("0", &str);
	str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free (str);
	return (counter);
}

size_t	convert_x_low(t_printf_info *info, va_list args)
{
	unsigned int	nbr;
	char			*str;
	size_t			counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	if (!nbr && !info->prec)
	{
		if (info->width)
		{
			str = ft_strdup("");
			str = get_width(info, &str);
			counter += ft_putstr_fd(str, 1);
			free(str);
		}
		return (counter);
	}
	str = ft_litoa_base(nbr, HEXBASELOW);
	str = get_precision_base(info, &str);
	if (info->alt && nbr)
			str = ft_strjoin_free("0x", &str);
	str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free (str);
	return (counter);
}

size_t	convert_x_up(t_printf_info *info, va_list args)
{
	unsigned int	nbr;
	char			*str;
	size_t			counter;

	counter = 0;
	nbr = va_arg(args, unsigned int);
	if (!nbr && !info->prec)
	{
		if (info->width)
		{
			str = ft_strdup("");
			str = get_width(info, &str);
			counter += ft_putstr_fd(str, 1);
			free(str);
		}
		return (counter);
	}
	str = ft_litoa_base(nbr, HEXBASEUP);
	str = get_precision_base(info, &str);
	if (info->alt && nbr)
			str = ft_strjoin_free("0X", &str);
	str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free (str);
	return (counter);
}
