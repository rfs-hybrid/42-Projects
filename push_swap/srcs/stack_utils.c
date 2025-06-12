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

void	ft_stack_prev_node_init(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	tmp = *stack;
	tmp->prev = last;
	tmp = tmp->next;
	while (tmp != *stack)
	{
		last = last->next;
		tmp->prev = last;
		tmp = tmp->next;
	}
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
