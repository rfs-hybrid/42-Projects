/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:08:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/11 15:27:40 by maaugust         ###   ########.fr       */
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
	if (a && *a)
	{
		swap(a);
		if (!check && *a != (*a)->next)
			ft_putendl_fd("sa", 1);
	}
}

void	sb(t_stack **b, bool check)
{
	if (b && *b)
	{
		swap(b);
		if (!check && *b != (*b)->next)
			ft_putendl_fd("sb", 1);
	}
}

void	ss(t_stack **a, t_stack **b, bool check)
{
	if (a && *a)
		swap(a);
	if (b && *b)
		swap(b);
	if (!check && ((a && *a && *a != (*a)->next)
		|| (b && *b && *b != (*b)->next)))
		ft_putendl_fd("ss", 1);
}
