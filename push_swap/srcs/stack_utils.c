/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:55 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/09 15:39:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_stack_is_sorted(t_stack *stack, bool is_rev)
{
	t_stack	*begin;

	if (!stack)
		return (false);
	begin = stack;
	while (begin != stack->next)
	{
		if ((!is_rev && stack->pos > stack->next->pos)
			|| (is_rev && stack->pos < stack->next->pos))
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_stack_maxindex(t_stack *stack)
{
	t_stack	*begin;
	int		max;

	begin = stack;
	max = stack->pos;
	stack = stack->next;
	while (stack != begin)
	{
		if (max < stack->pos)
			max = stack->pos;
		stack = stack->next;
	}
	return (max);
}

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
