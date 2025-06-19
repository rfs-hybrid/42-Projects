/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:50:05 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 19:44:14 by maaugust         ###   ########.fr       */
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
	if (non_lis_forward_offset(*stack) <= non_lis_backward_offset(*stack))
		while ((*stack)->lis)
			ft_run_rotation(stack, NULL, 0, false);
	else
		while ((*stack)->lis)
			ft_run_reverse_rotation(stack, NULL, 0, false);
}

void	ft_lis_sort(t_stack **a, t_stack **b, t_lis lis)
{
	int	pivot;

	pivot = ft_stack_size(*a) / 2 + ft_stack_size(*a) % 2;
	while (ft_stack_size(*a) != lis.size && ft_stack_size(*a) > 3
		&& !ft_stack_is_semi_sorted(*a, false))
	{
		if (ft_stack_size(*b) < 2 && ft_stack_size(*a) > 3)
		{
			if ((*a)->lis)
				rotate_to_non_lis(a);
			ft_run_push(a, b, 1, false);
			if (ft_stack_size(*b) == 2
				&& (*b)->val < pivot && (*b)->next->val > pivot)
				ft_run_swap(NULL, b, 1, false);
		}
		else if (!((*a)->lis))
		{
			ft_run_push(a, b, 1, false);
			if ((*b)->val < pivot)
				ft_run_rotation(NULL, b, 1, false);
		}
		else
			rotate_to_non_lis(a);
	}
}
