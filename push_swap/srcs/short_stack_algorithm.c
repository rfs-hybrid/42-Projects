/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_stack_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:20:42 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:44:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num_algorithm(t_stack **s, bool check)
{
	if ((*a)->prev == (*a)->next)
		ra(a, check);
	else if ((*s)->pos < (*s)->prev->pos && (*s)->pos < (*s)->next->pos)
	{
		sa(s, check);
		ra(s, check);
	}
	else if ((*s)->pos < (*s)->prev->pos)
		sa(s, check);
	else if ((*s)->pos < (*s)->next->pos)
		rra(s, check);
	else if ((*s)->prev->pos > (*s)->next->pos)
		ra(s, check);
	else
	{
		sa(s, check);
		rra(s, check);
	}
}

void	five_num_algorithm(t_stack **a, t_stack **b, int max)
{
	if (ft_stack_is_sorted(*a, true))
		sa(a, false);
	// (void) max;
	// pb(a, b, check);
	// pb(a, b, check);
	// if ((*b)->pos < (*b)->next->pos)
	// {
	// 	if (!((*a)->prev->pos < (*a)->pos && (*a)->prev->pos > (*a)->next->pos)
	// 		&& !((*a)->pos < (*a)->next->pos && (*a)->pos > (*a)->prev->pos))
	// 		ss(a, b, check);
	// 	else
	// 		sb(b, check);
	// }
	// three_num_algorithm(a, check);
	// while (((*b)->pos != 0 && (*b)->pos != max)
	// 	&& !((*a)->pos > (*b)->pos && (*a)->prev->pos < (*b)->pos))
	// 	ra(a, check);
	// pa(a, b);
	// while (b && *b && (*b)->pos != 0 && (*b)->pos != max
	// 	&& !((*a)->pos > (*b)->pos && (*a)->prev->pos < (*b)->pos))
	// 	ra(a);
	// pa(a, b);
	// if ((*a)->pos == max)
	// 	ra(a);
	// while (!ft_stack_is_sorted(*a))
	// 	rra(a);
}
