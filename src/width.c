/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:49:38 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/28 21:50:28 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *get_width(t_printf_info *info, char **str)
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
	while(len < info->width) 
	{
		if (info->pad == ' ')
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
	int	len;

	len = (int) ft_strlen(*str); 
	while(len < info->width) 
	{
		if (info->pad == ' ')
			*str = ft_strjoin_free(" ", str);
		else
			*str = ft_strjoin_free("0", str);
		len++;
	}
	return (*str);
}
