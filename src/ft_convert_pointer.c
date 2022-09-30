/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:09:49 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 01:54:05 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	convert_p(t_printf_info *info, va_list args)
{
	size_t				counter;
	char				*str;
	unsigned long int	hex_nbr;

	counter = 0;
	hex_nbr = va_arg(args, unsigned long int);
	if (!hex_nbr)
		str = ft_strdup("(nil)");
	else
	{
		str = ft_litoa_base(hex_nbr, HEXBASELOW);
		str = ft_strjoin_free("0x", &str);
	}
	str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free (str);
	return (counter);
}
