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

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd(n % 10 + 48, fd);
		return ;
	}
	else if (n > -10 && n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((n % 10 * (-1)) + 48, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n < 0)
		ft_putchar_fd((n % 10 * (-1)) + 48, fd);
	else
		ft_putchar_fd(n % 10 + 48, fd);
}
