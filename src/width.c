/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:49:38 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 01:55:45 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_width(t_printf_info *info, char **str)
{
	if (info->width == -1)
		return (*str);
	if (info->left)
		*str = get_left_justify(info, str);
	else
		*str = get_right_justify(info, str);
	return (*str);
}

char	*get_left_justify(t_printf_info *info, char **str)
{
	char	*tmp;
	int		len;

	len = (int) ft_strlen(*str);
	while (len < info->width)
	{
		if (info->pad == ' ' || info->prec != -1)
			tmp = ft_strjoin(*str, " ");
		else
			tmp = ft_strjoin(*str, "0");
		len++;
		free(*str);
		*str = tmp;
	}
	return (*str);
}

char	*get_right_justify(t_printf_info *info, char **str)
{
	int		len;
	int		neg;
	char	*new_str;

	len = (int) ft_strlen(*str);
	neg = 0;
	new_str = *str;
	if (**str == '-' && info->pad == '0' && (info->spec == 'd'\
			|| info->spec == 'i') && info->prec == -1)
	{
		new_str = ft_strtrim(*str, "-");
		free(*str);
		neg = 1;
	}
	while (len < info->width)
	{
		if (info->pad == ' ' || info->prec != -1)
			new_str = ft_strjoin_free(" ", &new_str);
		else
			new_str = ft_strjoin_free("0", &new_str);
		len++;
	}
	if (neg)
		new_str = ft_strjoin_free("-", &new_str);
	return (new_str);
}
