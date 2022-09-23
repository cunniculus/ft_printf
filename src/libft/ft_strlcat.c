/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 05:49:04 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/14 02:20:44 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	max;
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size == 0 || len_d >= size)
		return (len_s + size);
	max = size - len_d - 1;
	index = 0;
	while (src[index] != '\0' && index < max && len_d < size)
	{
		dst[len_d + index] = src[index];
		index++;
	}
	dst[len_d + index] = '\0';
	return (len_s + len_d);
}
