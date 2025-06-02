/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:55 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/02 14:49:16 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_stackadd_front(t_stack **stack, t_stack *new)
// {
// 	new->next = *stack;
// 	*stack = new;
// }

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack)
	{
		tmp = *stack;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*stack = new;
	}
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*begin;

	if (stack)
	{
		begin = *stack;
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			if (tmp == begin)
				break ;
			*stack = tmp;
		}
		stack = NULL;
	}
}
