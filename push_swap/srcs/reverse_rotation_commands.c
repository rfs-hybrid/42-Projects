/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:12:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 15:06:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rra(t_stack **a)
{
	if (a && *a && *a != (*a)->prev)
	{
		*a = (*a)->prev;
		ft_putendl_fd("rra", 1);
	}
}

static void	rrb(t_stack **b)
{
	if (b && *b && *b != (*b)->prev)
	{
		*b = (*b)->prev;
		ft_putendl_fd("rrb", 1);
	}
}

static void	rrr(t_stack **a, t_stack **b)
{
	if (a && *a && *a != (*a)->prev && b && *b && *b != (*b)->prev)
	{
		*a = (*a)->prev;
		*b = (*b)->prev;
		ft_putendl_fd("rrr", 1);
	}
}

void	ft_run_reverse_rotation(t_stack **a, t_stack **b, int op)
{
	if (op == 0)
		rra(a);
	else if (op == 1)
		rrb(b);
	else
		rrr(a, b);
}
