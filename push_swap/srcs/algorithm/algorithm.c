/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 19:42:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_min_val(t_stack **stack)
{
	t_stack	*current;
	int		min;
	int		size;
	int		rotations;

	ft_stack_reset_indexes(stack);
	current = *stack;
	min = ft_stack_min_val(*stack);
	while (current->val != min)
		current = current->next;
	size = ft_stack_size(*stack);
	rotations = current->idx;
	if (rotations < (size + 1) / 2)
		while (rotations--)
			ft_run_rotation(stack, NULL, 0, false);
	else
	{
		rotations = size - rotations;
		while (rotations--)
			ft_run_reverse_rotation(stack, NULL, 0, false);
	}
}

void	ft_algorithm(t_stack **a, t_stack **b, t_lis lis)
{
	ft_lis_sort(a, b, lis);
	if (ft_stack_size(*a) == 3 && !ft_stack_is_semi_sorted(*a, false))
		ft_run_swap(a, NULL, 0, false);
	ft_stack_sort(a, b);
	if (!ft_stack_is_sorted(*a, false))
		rotate_to_min_val(a);
}
