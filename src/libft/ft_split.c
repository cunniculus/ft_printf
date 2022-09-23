/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:12:03 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/14 01:22:51 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c);
static char		*get_word(const char *s, char c);
static char		**empty_split(void);
static void		setup_split(char **split, char *s_cpy, char c, size_t wc);

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*s_cpy;
	size_t	word_count;
	char	set[2];

	if (!s || !*s)
		return (empty_split());
	set[0] = c;
	set[1] = '\0';
	s_cpy = ft_strtrim(s, set);
	if (s_cpy == NULL || *s_cpy == '\0')
	{
		free(s_cpy);
		return (empty_split());
	}
	word_count = count_words(s_cpy, c);
	split = (char **) malloc((sizeof (char *)) * (word_count + 1));
	if (split == NULL)
		return (NULL);
	setup_split(split, s_cpy, c, word_count);
	free(s_cpy);
	return (split);
}

static size_t	count_words(char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
		{
			word_count++;
			while (*s && *s == c)
				s++;
		}
		else
			while (*s && *s != c)
				s++;
	}
	word_count++;
	return (word_count);
}

static char	*get_word(const char *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = (char *) ft_calloc(1, len + 1);
	if (!word)
		return (NULL);
	ft_memmove(word, s, len);
	return (word);
}

static char	**empty_split(void)
{
	char	**split;

	split = malloc(sizeof (split));
	split[0] = NULL;
	return (split);
}

static void	setup_split(char **split, char *s_cpy, char c, size_t wc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < wc)
	{
		split[i] = get_word(&s_cpy[j], c);
		i++;
		while (s_cpy[j] != c && s_cpy[j])
			j++;
		while (s_cpy[j] == c && s_cpy[j])
			j++;
		if (!*s_cpy)
			j++;
	}
	split[i] = NULL;
}
