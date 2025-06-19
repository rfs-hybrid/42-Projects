/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 16:08:33 by maaugust         ###   ########.fr       */
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
			ft_run_rotation(stack, NULL, 0);
	else
	{
		rotations = size - rotations;
		while (rotations--)
			ft_run_reverse_rotation(stack, NULL, 0);
	}
}

static void	find_target_ordered(t_stack **stack1, t_stack *stack2)
{
	t_stack	*current;
	int		max;
	int		min;
	int		size;

	current = *stack1;
	max = ft_stack_max_val(stack2);
	min = ft_stack_min_val(stack2);
	size = ft_stack_size(*stack1);
	while (size--)
	{
		if (current->val > max || current->val < min)
			while (stack2->val != min)
				stack2 = stack2->next;
		else
			while (!(current->val < stack2->val
					&& current->val > stack2->prev->val))
				stack2 = stack2->next;
		current->target = stack2;
		current = current->next;
	}
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*b))
	{
		ft_stack_reset_indexes(a);
		ft_stack_reset_indexes(b);
		stack_index_cost(a);
		stack_index_cost(b);
		find_target_ordered(b, *a);
		run_commands(a, b, find_cheapest(b));
	}
}

void	ft_run_algorithm(t_stack **a, t_stack **b, t_lis lis)
{
	ft_stack_lis_sort(a, b, lis);
	if (ft_stack_size(*a) == 3 && !ft_stack_is_semi_sorted(*a, false))
		ft_run_swap(a, NULL, 0);
	sort_stack(a, b);
	if (!ft_stack_is_sorted(*a, false))
		rotate_to_min_val(a);
}
