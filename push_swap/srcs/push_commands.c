/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:17:15 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack1, t_stack **stack2, t_stack *stack1_node)
{
	t_stack	*tmp;

	if (stack1_node == stack1_node->next)
		*stack1 = NULL;
	else
	{
		stack1_node->prev->next = stack1_node->next;
		stack1_node->next->prev = stack1_node->prev;
		*stack1 = stack1_node->next;
	}
	if (!*stack2)
	{
		stack1_node->next = stack1_node;
		stack1_node->prev = stack1_node;
		*stack2 = stack1_node;
		return ;
	}
	tmp = (*stack2)->prev;
	tmp->next = stack1_node;
	stack1_node->prev = tmp;
	stack1_node->next = *stack2;
	*stack2 = stack1_node;
}

void	pa(t_stack **a, t_stack **b, bool check)
{
	if (b && *b)
	{
		push(b, a, *b);
		if (!check)
			ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b, bool check)
{
	if (a && *a)
	{
		push(a, b, *a);
		if (!check)
			ft_printf("pb\n");
	}
}
