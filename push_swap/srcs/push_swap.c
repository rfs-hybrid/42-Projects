/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:24:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int max)
{
	if (max <= 3)
	{
		if ((*a)->prev == (*a)->next)
		{
			ra(a, false);
			return ;
		}
		three_num_algorithm(a, false);
	}
	else if (max <= 5)
		five_num_algorithm(a, b, max);
}
