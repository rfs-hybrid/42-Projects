/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_lis_num(int n, t_lis lis)
{
	while (lis.size--)
	{
		if (n == lis.arr[lis.size])
			return (true);
	}
	return (false);
}

int	ft_stack_lis_init(t_stack **a, t_stack **b, t_lis lis)
{
	int	total;

	total = 0;
	while (!ft_stack_is_sorted(*a, false))
	{
		if (!is_lis_num((*a)->idx, lis))
		{
			pb(a, b, false);
			if ((*b)->idx < lis.mid)
			{
				rb(b, false);
				total++;
			}
		}
		else
			ra(a, false);
		total++;
	}
	return (total);
}
