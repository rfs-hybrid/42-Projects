/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:08:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:18:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;

	if (*stack && (*stack)->next && *stack != (*stack)->next)
	{
		node1 = *stack;
		node2 = node1->next;
		if (node2->next != node1)
		{
			node1->prev->next = node2;
			node1->next->prev = node1;
			node1->next = node2->next;
			node2->prev = node1->prev;
			node2->next = node1;
			node1->prev = node2;
		}
		*stack = node2;
	}
}

void	sa(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->next)
	{
		swap(a);
		if (!check)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->next)
	{
		swap(b);
		if (!check)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->next && b && *b && *b != (*b)->next)
	{
		swap(a);
		swap(b);
		if (!check)
			ft_printf("ss\n");
	}
}
