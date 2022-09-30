/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:20:14 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 01:54:41 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (info->spec == 'o')
		return (convert_o(info, args));
	if (info->spec == 'x')
		return (convert_x_low(info, args));
	if (info->spec == 'X')
		return (convert_x_up(info, args));
	return (0);
}
