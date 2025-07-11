/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:08:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 20:12:26 by maaugust         ###   ########.fr       */
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
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
	}
	*stack = node2;
}

static void	sa(t_stack **a, bool check)
{
	if (a && *a && (*a)->next && *a != (*a)->next)
	{
		swap(a);
		if (!check)
			ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

static void	sb(t_stack **b, bool check)
{
	if (b && *b && (*b)->next && *b != (*b)->next)
	{
		swap(b);
		if (!check)
			ft_putendl_fd("sb", STDOUT_FILENO);
	}
}

static void	ss(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && (*a)->next && *a != (*a)->next)
		swap(a);
	if (b && *b && (*b)->next && *b != (*b)->next)
		swap(b);
	if (((a && *a && (*a)->next && *a != (*a)->next)
			|| (b && *b && (*b)->next && *b != (*b)->next))
		&& !check)
		ft_putendl_fd("ss", 1);
}

void	ft_run_swap(t_stack **a, t_stack **b, int op, bool check)
{
	if (op == 0)
		sa(a, check);
	else if (op == 1)
		sb(b, check);
	else
		ss(a, b, check);
}
