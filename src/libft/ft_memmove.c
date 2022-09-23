/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:48:49 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/14 01:16:08 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
