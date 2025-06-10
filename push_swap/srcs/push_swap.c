/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 15:41:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_memory(t_lis *lis, int **a_arr)
{
	free (*a_arr);
	free (lis->arr);
	ft_stackclear(&(lis->stack));
}

void	push_swap(t_stack **a, t_stack **b, int max)
{
	t_lis	lis;
	int		*a_array;
	(void)	b;

	if (ft_stack_is_sorted(*a, true))
		sa(a, false);
	a_array = ft_stack_to_array(*a, max);
	lis.arr = lis_sequence(a_array, max, &(lis.size));
	lis.stack = ft_array_to_stack(lis.arr, lis.size);
	if (!(lis.stack))
	{
		free_memory(&lis, &a_array);
		ft_stackclear(a);
		ft_print_error();
	}
	lis.mid = max / 2 + max % 2;
	lis_algorithm(a, b, lis, max);
	free_memory(&lis, &a_array);
}
