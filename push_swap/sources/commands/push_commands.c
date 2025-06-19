/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:36 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 15:25:54 by maaugust         ###   ########.fr       */
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
	(*stack2)->prev = stack1_node;
	*stack2 = stack1_node;
}

static void	pa(t_stack **a, t_stack **b)
{
	if (b && *b)
	{
		ft_putendl_fd("pa", 1);
		push(b, a, *b);
	}
}

static void	pb(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		ft_putendl_fd("pb", 1);
		push(a, b, *a);
	}
}

void	ft_run_push(t_stack **a, t_stack **b, int op)
{
	if (op == 0)
		pa(a, b);
	else
		pb(a, b);
}
