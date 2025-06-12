/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 17:31:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->next)
	{
		rotation(a);
		if (!check)
			ft_putendl_fd("ra", 1);
	}
}

void	rb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->next)
	{
		rotation(b);
		if (!check)
			ft_putendl_fd("rb", 1);
	}
}

void	rr(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->next && b && *b && *b != (*b)->next)
	{
		rotation(a);
		rotation(b);
		if (!check)
			ft_putendl_fd("rr", 1);
	}
}
