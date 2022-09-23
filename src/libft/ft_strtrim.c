/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:38:05 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/14 00:12:26 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_char_to_trim(char c, const char *set);
static size_t	get_trimmed_len(const char *s, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	t_len;

	if (!s1)
		return (NULL);
	while (is_char_to_trim(*s1, set))
		s1++;
	t_len = get_trimmed_len(s1, set);
	trimmed = ft_calloc(1, t_len + 1);
	if (!trimmed)
		return (NULL);
	trimmed = ft_memmove(trimmed, s1, t_len);
	return (trimmed);
}

static size_t	is_char_to_trim(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_trimmed_len(const char *s, const char *set)
{
	int	i;

	if (!*s)
		return (0);
	i = ft_strlen(s) - 1;
	while (is_char_to_trim(s[i], set))
		i--;
	return (i + 1);
}	
