/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:23:58 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/09 22:02:00 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		s_len;

	s_len = ft_strlen(s);
	new_string = (char *) malloc(s_len + 1);
	ft_memmove (new_string, s, s_len + 1);
	return (new_string);
}
