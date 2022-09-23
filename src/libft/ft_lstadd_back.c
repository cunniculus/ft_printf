/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 04:01:12 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/14 02:11:14 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// adds new list to last position of list. 
// user must make sure that new list or new node is NULL-terminated
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}
