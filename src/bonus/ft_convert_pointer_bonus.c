/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:09:49 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/29 19:35:46 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

size_t	convert_p(t_printf_info *info, va_list args)
{
	size_t				counter;
	char				*str;
	unsigned long int	hex_nbr;

	counter = 0;
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
	return (counter);
}
