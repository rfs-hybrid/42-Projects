/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 19:03:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static bool	is_lis_sorted(t_stack **a, t_lis lis, t_stack *begin)
// {
// 	while (lis.size--)
// 	{
// 		if ((*a)->pos != lis.stack->pos)
// 		{
// 			*a = begin;
// 			return (false);
// 		}
// 		*a = (*a)->next;
// 		lis.stack = lis.stack->next;
// 	}
// 	*a = begin;
// 	return (true);
// }

int	ft_stack_lis_init(t_stack **a, t_stack **b, t_lis lis)
{
	int	total;

	total = 0;
	while (!ft_stack_is_sorted(*a, false))
	{
		if ((*a)->idx != lis.stack->idx)
		{
			pb(a, b, false);
			if ((*b)->idx < lis.mid)
			{
				rb(b, false);
				total++;
			}
		}
		// else if (is_lis_sorted(a, lis, *a))
		// {
		// 	while ((max-- + 1) > lis.size)
		// 	{
		// 		rra(a, false);
		// 		if (!ft_stack_is_sorted(*a, false) && (*a)->pos > (*a)->next->pos)
		// 		{
		// 			pb(a, b, false);
		// 			if ((*b)->pos < lis.mid)
		// 			{
		// 				rb(b, false);
		// 				total++;
		// 			}
		// 			total++;
		// 		}
		// 		total++;
		// 	}
		// }
		else
		{
			ra(a, false);
			lis.stack = lis.stack->next;
		}
		total++;
	}
	return (total);
}
