/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 00:08:22 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 00:08:29 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

char *get_precision_diu(t_printf_info *info, char **str)
{
	int		len;
	char	*tmp;
	int		neg;

	neg = FALSE;
	tmp = *str;
	if (**str == '-')
	{
		tmp = ft_strtrim(*str, "-");
		free(*str);
		neg = TRUE;
	}
	len = (int) ft_strlen(tmp); 
	while(len < info->prec) 
	{
		tmp = ft_strjoin_free("0", &tmp);
		len++;
	}
	if (info->showsign && !neg && info->spec != 'u')
	{
		tmp = ft_strjoin_free("+", &tmp);
	}
	else if (info->space && !neg && info->spec != 'u') 
	{
		tmp = ft_strjoin_free(" ", &tmp);
	}
	if (neg)
		tmp = ft_strjoin_free("-", &tmp);
	return (tmp);
}

char *get_precision_s(t_printf_info *info, char **str)
{
	*str = ft_substr(*str, 0, info->prec);
	return (*str);
}

char *get_precision_base(t_printf_info *info, char **str)
{
	int		len;

	if (!info->prec)
		return (*str);
	len = (int) ft_strlen(*str); 
	while(len < info->prec) 
	{
		*str = ft_strjoin_free("0", str);
		len++;
	}
	return(*str);
}

