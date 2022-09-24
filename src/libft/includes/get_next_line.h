/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:50:48 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/23 02:09:38 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef TRUE
#  define TRUE 42
# endif

# ifndef FALSE
#  define FALSE 0
# endif

char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char **s1, char *s2);
int			ft_strlen_gnl(char *str);

#endif
