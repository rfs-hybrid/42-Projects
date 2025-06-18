/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:50:05 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/18 16:35:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	non_lis_forward_offset(t_stack *stack)
{
	t_stack	*current;
	int		offset;

	current = stack;
	offset = 0;
	while (current->lis)
	{
		current = current->next;
		offset++;
	}
	return (offset);
}

static int	non_lis_backward_offset(t_stack *stack)
{
	t_stack	*current;
	int		offset;

	current = stack;
	offset = 0;
	while (current->lis)
	{
		current = current->prev;
		offset++;
	}
	return (offset);
}

static void	rotate_to_non_lis(t_stack **stack)
{
	int	forward;
	int	backward;

	forward = non_lis_forward_offset(*stack);
	backward = non_lis_backward_offset(*stack);
	if (forward <= backward)
		while ((*stack)->lis)
			ft_run_rotation(stack, NULL, 0);
	else
		while ((*stack)->lis)
			ft_run_reverse_rotation(stack, NULL, 0);
}

static void	find_target_reverse_ordered(t_stack **stack1, t_stack *stack2)
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
		if (!current->lis)
		{
			if (current->val > max || current->val < min)
				while (stack2->val != max)
					stack2 = stack2->next;
			else
				while (!(current->val > stack2->val
						&& current->val < stack2->prev->val))
					stack2 = stack2->next;
			current->target = stack2;
		}
		current = current->next;
	}
}

void	ft_stack_lis_sort(t_stack **a, t_stack **b, t_lis lis)
{
	while (ft_stack_size(*a) != lis.size && !ft_stack_is_semi_sorted(*a, false))
	{
		while (ft_stack_size(*b) < 2)
		{
			if ((*a)->lis)
				rotate_to_non_lis(a);
			ft_run_push(a, b, 1);
		}
		if (!((*a)->lis))
		{
			stack_index_cost(a);
			stack_index_cost(b);
			find_target_reverse_ordered(a, *b);
			run_commands(a, b, find_cheapest(a), true);
		}
		else
			rotate_to_non_lis(a);
		ft_stack_reset_indexes(a);
		ft_stack_reset_indexes(b);
	}
}
