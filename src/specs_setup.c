/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 01:19:44 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 16:12:17 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width_setup(const char **format, t_printf_info *info);
static void	precision_setup(const char **format, t_printf_info *info);
static void	flags_setup(const char **format, t_printf_info *info);

void	init_specification_info(t_printf_info *info)
{
	info->alt = FALSE;
	info->space = FALSE;
	info->left = FALSE;
	info->showsign = FALSE;
	info->pad = ' ';
	info->width = -1;
	info->prec = -1;
	info->spec = '\0';
}

int	setup_specification_info(const char **format, size_t *counter, \
		t_printf_info *info)
{
	flags_setup(format, info);
	if ((info->left && info->pad) || info->spec == 'd' || info->spec == 'i'\
			|| info->spec == 'x' || info->spec == 'X')
		info->pad = ' ';
	if (ft_isdigit(**format))
		width_setup(format, info);
	if (**format == '.')
		precision_setup(format, info);
	if (char_is_specifier(**format) || **format == '%')
		info->spec = **format;
	return (*counter);
}

static void	flags_setup(const char **format, t_printf_info *info)
{
	while (char_is_flag(**format))
	{
		if (**format == '#')
			info->alt = TRUE;
		if (**format == ' ')
			info->space = TRUE;
		if (**format == '-')
			info->left = TRUE;
		if (**format == '+')
			info->showsign = TRUE;
		if (**format == '0')
			info->pad = '0';
		(*format)++;
	}
}

static void	width_setup(const char **format, t_printf_info *info)
{
	info->width = 0;
	while (ft_isdigit(**format))
	{
		info->width = info->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	precision_setup(const char **format, t_printf_info *info)
{
	(*format)++;
	info->prec = 0;
	while (**format == '0')
		(*format)++;
	while (ft_isdigit(**format))
	{
		info->prec = info->prec * 10 + (**format - '0');
		(*format)++;
	}
}
