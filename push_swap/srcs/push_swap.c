/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 18:54:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_memory(t_lis *lis, int **a_arr)
{
	free (*a_arr);
	free (lis->arr);
	ft_stackclear(&(lis->stack));
}

void	push_swap(t_stack **a, t_stack **b, int size)
{
	t_lis	lis;
	int		*a_array;
	(void)	b;

	if (ft_stack_is_sorted(*a, true))
		sa(a, false);
	a_array = ft_stack_to_array(*a, size);
	lis.arr = lis_sequence(a_array, size, &(lis.size));
	lis.stack = ft_array_to_stack(lis.arr, lis.size);
	if (!(lis.stack))
	{
		free_memory(&lis, &a_array);
		ft_stackclear(a);
		ft_print_error();
	}
	lis.mid = size / 2 + size % 2;
	lis_algorithm(a, b, lis);
	free_memory(&lis, &a_array);
}
