/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:45:12 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/07 05:41:34 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	int		digit;
	char	nbr_to_print[17];
	int		nbr_cpy;
	int		counter;

	nbr_cpy = nbr;
	digit = 1;
	while (nbr_cpy >= 10 || nbr_cpy <= -10)
	{
		nbr_cpy /= 10;
		digit++;
	}
	counter = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		counter++;
	}
	nbr_to_print[digit] = '\0';
	if (!nbr)
		nbr_to_print[0] = '0';
	while (nbr)
	{
		digit--;
		if (nbr >= 0)
			nbr_to_print[digit] = nbr % 10 + '0';
		else
			nbr_to_print[digit] = (nbr % 10) * (-1) + '0';
		nbr = nbr / 10;
	}
	ft_putstr_fd(nbr_to_print, fd);
	return (counter + ft_strlen(nbr_to_print));
}

