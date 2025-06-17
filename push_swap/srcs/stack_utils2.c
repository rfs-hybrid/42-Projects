/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:09:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 16:34:36 by maaugust         ###   ########.fr       */
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

int	ft_stack_max_val(t_stack *stack)
{
	t_stack	*begin;
	int		max;

	begin = stack;
	max = stack->val;
	stack = stack->next;
	while (stack != begin)
	{
		if (max < stack->val)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int	ft_stack_min_val(t_stack *stack)
{
	t_stack	*begin;
	int		min;

	begin = stack;
	min = stack->val;
	stack = stack->next;
	while (stack != begin)
	{
		if (min > stack->val)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

void	ft_stack_reset_indexes(t_stack **stack)
{
	int	size;
	int	i;

	size = ft_stack_size(*stack);
	i = -1;
	while (++i < size)
	{
		(*stack)->target = NULL;
		(*stack)->idx = i;
		(*stack)->top = (i < (size + 1) / 2);
		*stack = (*stack)->next;
	}
}
