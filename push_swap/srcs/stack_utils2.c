/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:09:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 18:12:50 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	t_stack	*begin;
	int		size;

	size = 0;
	if (stack)
	{
		size++;
		begin = stack;
		stack = stack->next;
		while (stack != begin)
		{
			size++;
			stack = stack->next;
		}
	}
	return (size);
}

int	ft_stack_max(t_stack *stack)
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

int	ft_stack_min(t_stack *stack)
{
	t_stack	*begin;
	int		min;

	begin = stack;
	min = stack->pos;
	stack = stack->next;
	while (stack != begin)
	{
		if (min > stack->pos)
			min = stack->pos;
		stack = stack->next;
	}
	return (min);
}
