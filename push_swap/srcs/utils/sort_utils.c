/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:09:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 18:13:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_stack_is_sorted(t_stack *stack, bool is_rev)
{
	t_stack	*begin;

	if (!stack || stack->next == stack)
		return (true);
	begin = stack;
	stack = stack->next;
	while (begin != stack)
	{
		if ((!is_rev && stack->prev->val > stack->val)
			|| (is_rev && stack->prev->val < stack->val))
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	ft_stack_is_semi_sorted(t_stack *stack, bool is_rev)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (true);
	current = stack->next;
	while (current != stack)
	{
		if (ft_stack_is_sorted(current, is_rev))
			return (true);
		current = current->next;
	}
	return (ft_stack_is_sorted(stack, is_rev));
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
