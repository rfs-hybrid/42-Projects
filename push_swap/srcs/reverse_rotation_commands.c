/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:12:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 16:43:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotation(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	rra(t_stack **a, bool check)
{
	if (a && *a && *a != (*a)->prev)
	{
		reverse_rotation(a);
		if (!check)
			ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_stack **b, bool check)
{
	if (b && *b && *b != (*b)->prev)
	{
		reverse_rotation(b);
		if (!check)
			ft_putendl_fd("rrb", 1);
	}
}

void	rrr(t_stack **a, t_stack **b, bool check)
{
	if (a && *a && *a != (*a)->prev && b && *b && *b != (*b)->prev)
	{
		reverse_rotation(a);
		reverse_rotation(b);
		if (!check)
			ft_putendl_fd("rrr", 1);
	}
}
