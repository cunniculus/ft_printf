/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:32:00 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/07 03:54:37 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// counts number of digits; if n < 0, function returns number of digits plus 1
static int	number_digits(int n);

char	*ft_itoa(int n)
{
	char	*s;
	int		nd;

	nd = number_digits(n);
	s = (char *) malloc(nd + 1);
	if (s == NULL)
		return (NULL);
	s[nd--] = '\0';
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
		s[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			s[nd] = n % 10 + 48;
		else
			s[nd] = (n % 10) * (-1) + 48;
		n = n / 10;
		nd--;
	}
	return (s);
}

static int	number_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
