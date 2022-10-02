/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:02:29 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 18:02:35 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"	

static int	parce_format(const char **format, va_list args, size_t *counter);
static int	converter(const char **format, va_list args, size_t *counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	printed_char_counter;

	if (!format)
		return (-1);
	va_start(args, format);
	printed_char_counter = 0;
	parce_format(&format, args, &printed_char_counter);
	va_end(args);
	return (printed_char_counter);
}

static int	parce_format(const char **format, va_list args, size_t *counter)
{
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			converter(format, args, counter);
		}
		else
		{
			ft_putchar_fd(**format, 1);
			(*counter)++;
		}
		(*format)++;
	}
	return (*counter);
}

static int	converter(const char **format, va_list args, size_t *counter)
{
	t_printf_info	info;

	init_specification_info(&info);
	setup_specification_info(format, counter, &info);
	convert_printf(&info, args, counter);
	return (0);
}
