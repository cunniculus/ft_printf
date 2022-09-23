/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:51:06 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/06 22:35:06 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	buff_size;

	new_string = NULL;
	buff_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = (char *) ft_calloc(1, buff_size);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, buff_size);
	ft_strlcat(new_string, s2, buff_size);
	return (new_string);
}
