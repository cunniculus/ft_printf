/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:20:57 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/28 23:01:21 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	buff_size;
	size_t	s_len;

	if (!s)
		return (NULL);
	substring = NULL;
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substring = (char *) malloc(1);
		substring[0] = '\0';
		return (substring);
	}
	else if (ft_strlen(s + start) >= len)
		buff_size = len + 1;
	else
		buff_size = ft_strlen(s + start) + 1;
	substring = (char *) ft_calloc(1, buff_size);
	if (substring == NULL)
		return (NULL);
	if (start < s_len)
		ft_strlcpy(substring, s + start, buff_size);
	return (substring);
}
