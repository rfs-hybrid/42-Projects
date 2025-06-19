/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:07:35 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 19:43:33 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_cost(t_stack *node1, t_stack *node2)
{
	int	cost;

	cost = node1->cost;
	if (node2)
	{
		if (node1->top != node2->top)
			cost += node2->cost;
		else if (node1->cost < node2->cost)
			cost = node2->cost;
	}
	return (cost);
}

static t_stack	*find_cheapest(t_stack **stack)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		next_cost;
	int		prev_cost;

	cheapest = *stack;
	prev_cost = calculate_cost(*stack, (*stack)->target);
	current = (*stack)->next;
	while (current != *stack)
	{
		if (!(current->lis))
		{
			next_cost = calculate_cost(current, current->target);
			if (next_cost < prev_cost)
			{
				cheapest = current;
				prev_cost = next_cost;
			}
		}
		current = current->next;
	}
	return (cheapest);
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

static void	stack_index_cost(t_stack **stack)
{
	t_stack	*current;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_stack_size(*stack);
	current = *stack;
	i = -1;
	while (++i < size)
	{
		if (current->top)
			current->cost = current->idx;
		else
			current->cost = size - current->idx;
		current = current->next;
	}
}

void	ft_stack_sort(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*b))
	{
		ft_stack_reset_indexes(a);
		ft_stack_reset_indexes(b);
		stack_index_cost(a);
		stack_index_cost(b);
		find_target_ordered(b, *a);
		ft_run_commands(a, b, find_cheapest(b));
	}
}
