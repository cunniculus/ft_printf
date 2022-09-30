/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_and_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:05:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 16:28:55 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_in_order(t_printf_info *info, char c, char *pad);
static char		*get_prec_and_width_s(t_printf_info *info, char **str);

size_t	convert_c_and_percent(t_printf_info *info, va_list args)
{
	size_t	counter;
	char	*str;
	char	c;

	str = ft_calloc (1, sizeof (char));
	if (info->width >= 0)
	{
		str = get_width(info, &str);
		str[ft_strlen(str) - 1] = '\0';
	}
	if (info->spec == '%')
		c = '%';
	else
		c = (unsigned char) va_arg(args, int);
	counter = print_in_order(info, c, str);
	free (str);
	return (counter);
}

static size_t	print_in_order(t_printf_info *info, char c, char *pad)
{
	size_t	counter;

	counter = 0;
	if (info->left)
	{
		counter += ft_putchar_fd(c, 1);
		counter += ft_putstr_fd(pad, 1);
	}
	else
	{
		counter += ft_putstr_fd(pad, 1);
		counter += ft_putchar_fd(c, 1);
	}
	return (counter);
}

size_t	convert_s(t_printf_info *info, va_list args)
{
	size_t	counter;
	char	*str;

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
	str = get_prec_and_width_s(info, &str);
	counter += ft_putstr_fd(str, 1);
	free(str);
	return (counter);
}

static char	*get_prec_and_width_s(t_printf_info *info, char **str)
{
	char	*tmp;

	tmp = *str;
	if (info->prec >= 0)
	{
		*str = get_precision_s(info, str);
		free(tmp);
	}
	if (info->width >= 0)
		*str = get_width(info, str);
	return (*str);
}
