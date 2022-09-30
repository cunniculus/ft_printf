/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:25:21 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/30 19:09:06 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_is_flag(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}

int	char_is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'\
			|| c == 'x' || c == 'X' || c == 'o')
		return (TRUE);
	return (FALSE);
}

int	ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned long int	b;
	int					digit;
	char				nbr_to_print[17];
	unsigned long int	nbr_cpy;

	nbr_cpy = nbr;
	b = ft_strlen(base);
	digit = 1;
	while (nbr_cpy >= b)
	{
		nbr_cpy /= b;
		digit++;
	}
	nbr_to_print[digit] = '\0';
	if (!nbr)
		nbr_to_print[0] = '0';
	while (nbr)
	{
		digit--;
		nbr_to_print[digit] = base[nbr % b];
		nbr = nbr / b;
	}
	ft_putstr_fd(nbr_to_print, 1);
	return (ft_strlen(nbr_to_print));
}

char	*ft_litoa_base(unsigned long int nbr, char *base)
{
	unsigned long int	b;
	int					digit;
	char				*nbr_to_print;
	unsigned long int	nbr_cpy;

	nbr_cpy = nbr;
	b = ft_strlen(base);
	digit = 1;
	while (nbr_cpy >= b)
	{
		nbr_cpy /= b;
		digit++;
	}
	nbr_to_print = malloc(sizeof(char) * (digit + 1));
	nbr_to_print[digit] = '\0';
	if (!nbr)
		nbr_to_print[0] = '0';
	while (nbr)
	{
		digit--;
		nbr_to_print[digit] = base[nbr % b];
		nbr = nbr / b;
	}
	return (nbr_to_print);
}

char	*ft_strjoin_free(char *s1, char **s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(*s2) + ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (*s2 && (*s2)[j])
	{
		str[i + j] = (*s2)[j];
		j++;
	}
	str[len] = '\0';
	if (*s2)
		free(*s2);
	return (str);
}
