/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:20:37 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/05 20:51:23 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	n = 0;
	while (ft_isdigit(*nptr))
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	return (sign * n);
}

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\n' || c == '\r' || \
		c == '\t' || c == '\v' || c == ' ')
		return (TRUE);
	return (FALSE);
}
