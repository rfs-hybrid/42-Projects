/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:18:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->prev)
	{
		rotation(a);
		if (!check)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->prev)
	{
		rotation(b);
		if (!check)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->prev && b && *b && *b != (*b)->prev)
	{
		rotation(a);
		rotation(b);
		if (!check)
			ft_printf("rr\n");
	}
}
