/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:41:06 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/12 20:18:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else if (new)
		{
			*lst = new;
		}
	}
}
