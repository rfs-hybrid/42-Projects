/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:55 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 18:12:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
