/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:33:55 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 18:12:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd("Error", 2);
	exit(1);
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
