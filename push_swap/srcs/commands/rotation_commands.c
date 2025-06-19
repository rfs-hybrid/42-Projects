/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 20:12:07 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->next)
	{
		*a = (*a)->next;
		if (!check)
			ft_putendl_fd("ra", STDOUT_FILENO);
	}
}

static void	rb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->next)
	{
		*b = (*b)->next;
		if (!check)
			ft_putendl_fd("rb", STDOUT_FILENO);
	}
}

static void	rr(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->next && b && *b && *b != (*b)->next)
	{
		*a = (*a)->next;
		*b = (*b)->next;
		if (!check)
			ft_putendl_fd("rr", STDOUT_FILENO);
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
