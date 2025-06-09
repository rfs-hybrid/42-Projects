/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/09 19:35:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_memory(t_stack **lis_s, int **lis_arr, int **a_arr)
{
	free (*a_arr);
	free (*lis_arr);
	ft_stackclear(lis_s);
}

void	push_swap(t_stack **a, t_stack **b, int max)
{
	t_stack	*lis_stack;
	int		*lis_array;
	int		*a_array;
	int		lis_len;

	if (ft_stack_is_sorted(*a, true))
		sa(a, false);
	a_array = stack_to_array(*a, max);
	lis_array = lis_sequence(a_array, max, &lis_len);
	lis_stack = array_to_stack(lis_array, lis_len);
	if (!lis_stack)
	{
		free_memory(&lis_stack, &lis_array, &a_array);
		ft_stackclear(a);
		print_error();
	}
	free_memory(&lis_stack, &lis_array, &a_array);
}
