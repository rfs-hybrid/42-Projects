/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:57:35 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/08 20:57:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_array(t_stack *s, int max)
{
	int	*arr;
	int	i;

	arr = (int *) ft_calloc(max, sizeof(int));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < max)
	{
		arr[i] = s->pos;
		s = s->next;
	}
	return (arr);
}

t_stack	*create_list_from_array(int *arr)
{
	t_stack	*stack;

	return (stack);
}
