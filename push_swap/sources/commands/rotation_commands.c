/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 15:08:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra(t_stack **a)
{
	if (a && *a && *a != (*a)->next)
	{
		*a = (*a)->next;
		ft_putendl_fd("ra", 1);
	}
}

static void	rb(t_stack **b)
{
	if (b && *b && *b != (*b)->next)
	{
		*b = (*b)->next;
		ft_putendl_fd("rb", 1);
	}
}

static void	rr(t_stack **a, t_stack **b)
{
	if (a && *a && *a != (*a)->next && b && *b && *b != (*b)->next)
	{
		*a = (*a)->next;
		*b = (*b)->next;
		ft_putendl_fd("rr", 1);
	}
}

void	ft_run_rotation(t_stack **a, t_stack **b, int op)
{
	if (op == 0)
		ra(a);
	else if (op == 1)
		rb(b);
	else
		rr(a, b);
}
