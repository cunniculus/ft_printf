/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:50:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/23 02:13:14 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	nl_in_temp(char *temp, int total_read);
static char	*update_temp(char **temp, char *line);
static char	*get_line(char *str);
static int	error_found(int fd);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp[1024];
	char		*line;
	int			current_read;
	int			total_read;

	if (error_found(fd))
		return (0);
	total_read = 0;
	current_read = 0;
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	while (!nl_in_temp(temp[fd], total_read))
	{
		total_read = total_read + current_read;
		current_read = read(fd, buffer, BUFFER_SIZE);
		if (current_read <= 0)
			break ;
		buffer[current_read] = '\0';
		temp[fd] = ft_strjoin_gnl(&temp[fd], buffer);
	}
	line = get_line(temp[fd]);
	temp[fd] = update_temp(&temp[fd], line);
	free(buffer);
	return (line);
}

static int	nl_in_temp(char *temp, int total_read)
{
	if (!temp)
		return (FALSE);
	while (temp[total_read])
	{
		if ('\n' == temp[total_read])
			return (TRUE);
		total_read++;
	}
	return (FALSE);
}

static char	*get_line(char *str)
{
	int		len;
	int		i;
	char	*line;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*update_temp(char **temp, char *line)
{
	int		len;
	int		cut;
	int		i;
	char	*new_temp;

	if (!(*temp))
		return (0);
	len = ft_strlen_gnl(*temp);
	cut = ft_strlen_gnl(line);
	if (len == cut)
	{
		free(*temp);
		return (NULL);
	}
	new_temp = malloc(sizeof(char) * (len + 1 - cut));
	i = 0;
	while ((*temp)[cut])
	{
		new_temp[i] = (*temp)[cut];
		cut++;
		i++;
	}
	new_temp[i] = '\0';
	free (*temp);
	return (new_temp);
}

static int	error_found(int fd)
{
	if (fd == 0 || fd == 2)
		return (FALSE);
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (TRUE);
	return (FALSE);
}
