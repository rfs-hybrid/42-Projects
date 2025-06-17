/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 17:30:06 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_stack_lis_sort(t_stack **a, t_stack **b, t_lis lis)
{
	while (ft_stack_size(*a) != lis.size && !ft_stack_is_semi_sorted(*a, false))
	{
		while (ft_stack_size(*b) < 2)
		{
			while ((*a)->lis)
				ft_run_rotation(a, NULL, 0);
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
			ft_run_rotation(a, NULL, 0);
		ft_stack_reset_indexes(a);
		ft_stack_reset_indexes(b);
	}
}

void	ft_lis_algorithm(t_stack **a, t_stack **b, t_lis lis)
{
	int	i;

	ft_stack_lis_sort(a, b, lis);
	i = -1;
	ft_putendl_fd("\n--------------------------------------------------------------------------------------------------", 1);
	ft_putstr_fd("LIS: ", 1);
	while (++i < ft_stack_size(*a))
	{
		if ((*a)->lis)
			ft_printf ("%d ", (*a)->val);
		*a = (*a)->next;
	}
	i = -1;
	ft_putendl_fd("\n--------------------------------------------------------------------------------------------------", 1);
	ft_putstr_fd("STACK A: ", 1);
	while (++i < ft_stack_size(*a))
	{
		ft_printf ("%d ", (*a)->val);
		*a = (*a)->next;
	}
	ft_putchar_fd('\n', 1);
	i = -1;
	ft_putendl_fd("--------------------------------------------------------------------------------------------------", 1);
	ft_putstr_fd("STACK B: ", 1);
	while (++i < ft_stack_size(*b))
	{
		ft_printf ("%d ", (*b)->val);
		*b = (*b)->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("--------------------------------------------------------------------------------------------------\n", 1);
}
