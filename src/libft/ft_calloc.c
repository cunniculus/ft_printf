/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:37:14 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/13 23:30:24 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;
	size_t	alloc_size;

	buff = NULL;
	if (size == 0 || nmemb == 0 || size > INT_MAX / nmemb)
		return (NULL);
	alloc_size = nmemb * size;
	buff = malloc(alloc_size);
	if (!buff)
		return (NULL);
	return (ft_memset(buff, '\0', alloc_size));
}
