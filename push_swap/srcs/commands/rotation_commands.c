/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 19:36:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->next)
	{
		*a = (*a)->next;
		if (!check)
			ft_putendl_fd("ra", 1);
	}
}

static void	rb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->next)
	{
		*b = (*b)->next;
		if (!check)
			ft_putendl_fd("rb", 1);
	}
}

static void	rr(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->next && b && *b && *b != (*b)->next)
	{
		*a = (*a)->next;
		*b = (*b)->next;
		if (!check)
			ft_putendl_fd("rr", 1);
	}
}

void	ft_run_rotation(t_stack **a, t_stack **b, int op, bool check)
{
	if (op == 0)
		ra(a, check);
	else if (op == 1)
		rb(b, check);
	else
		rr(a, b, check);
}
