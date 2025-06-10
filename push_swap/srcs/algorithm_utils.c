/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 17:11:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_lis_init(t_stack **a, t_stack **b, t_lis lis, int max)
{
	int	i;

	i = -1;
	while (++i < max)
	{
		if ((*a)->pos != lis.stack->pos)
		{
			pb(a, b, true);
			if ((*b)->pos < lis.mid)
				rb(b, true);
		}
		else
		{
			ra(a, true);
			lis.stack = lis.stack->next;
		}
	}
}
