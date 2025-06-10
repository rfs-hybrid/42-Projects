/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:57:35 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 14:42:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stack_to_array(t_stack *s, int max)
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

t_stack	*ft_array_to_stack(int *arr, int len)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	if (!arr)
		return (NULL);
	i = -1;
	stack = NULL;
	while (++i < len)
	{
		new = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!new)
		{
			ft_stackclear(&stack);
			return (NULL);
		}
		new->pos = arr[i];
		new->next = NULL;
		ft_stackadd_back(&stack, new);
	}
	ft_prev_node_init(&stack);
	return (stack);
}
