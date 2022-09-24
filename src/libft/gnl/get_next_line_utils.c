/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:50:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/22 23:47:43 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen_gnl(*s1) + ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (*s1 && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[len] = '\0';
	if (*s1)
		free(*s1);
	return (str);
}
