/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:08:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 15:16:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*node1;
	t_stack	*node2;

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

static void	sa(t_stack **a)
{
	if (a && *a && (*a)->next && *a != (*a)->next)
	{
		swap(a);
		ft_putendl_fd("sa", 1);
	}
}

static void	sb(t_stack **b)
{
	if (b && *b && (*b)->next && *b != (*b)->next)
	{
		swap(b);
		ft_putendl_fd("sb", 1);
	}
}

static void	ss(t_stack **a, t_stack **b)
{
	if (a && *a && (*a)->next && *a != (*a)->next)
		swap(a);
	if (b && *b && (*b)->next && *b != (*b)->next)
		swap(b);
	if ((a && *a && (*a)->next && *a != (*a)->next)
		|| (b && *b && (*b)->next && *b != (*b)->next))
		ft_putendl_fd("ss", 1);
}

void	ft_run_swap(t_stack **a, t_stack **b, int op)
{
	if (op == 0)
		sa(a);
	else if (op == 1)
		sb(b);
	else
		ss(a, b);
}
