/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:20:11 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/04 22:03:58 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //definition of size_t

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
