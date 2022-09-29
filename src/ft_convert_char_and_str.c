/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_and_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:05:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/29 21:34:11 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	convert_c_and_percent(t_printf_info *info, va_list args)
{
	size_t				counter;
	char *str;

	counter = 0;
	str = ft_calloc (1, sizeof (char));
	if (info->width >= 0)
	{
		str = get_width(info, &str);
		str[ft_strlen(str) - 1] = '\0';
	}
	if (info->left)
	{
		if (info->spec == '%')
			counter += ft_putchar_fd('%', 1);
		else
			counter += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
		counter += ft_putstr_fd(str, 1);
	}
	else
	{
		counter += ft_putstr_fd(str, 1);
		if (info->spec == '%')
			counter += ft_putchar_fd('%', 1);
		else
			counter += ft_putchar_fd((unsigned char) va_arg(args, int), 1);
	}
	free (str);
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
	{
		str = ft_strdup("(null)");
		if (info->prec > 0 && info->prec < 6)
		{
			free(str);
			return (0);
		}
	}
	else
		str = ft_strdup(str);
	tmp = str;
	if (info->prec >= 0)
	{
		str = get_precision_s(info, &str);
		free(tmp);
	}
	if (info->width >= 0)
		str = get_width(info, &str);
	counter += ft_putstr_fd(str, 1);
	free(str);
	return (counter);
}
