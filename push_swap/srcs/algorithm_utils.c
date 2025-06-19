/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 15:48:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_opposite(t_stack **s1, t_stack **s2, t_stack *node)
{
	while (node->cost-- > 0)
	{
		if (node->top)
			ft_run_rotation(s1, s2, 1);
		else
			ft_run_reverse_rotation(s1, s2, 1);
	}
	while (node->target->cost-- > 0)
	{
		if (node->target->top)
			ft_run_rotation(s1, s2, 0);
		else
			ft_run_reverse_rotation(s1, s2, 0);
	}
	return (ft_run_push(s1, s2, 0));
}

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

t_stack	*find_cheapest(t_stack **stack)
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

void	run_commands(t_stack **s1, t_stack **s2, t_stack *node)
{
	if (node->top != node->target->top)
		return (run_opposite(s1, s2, node));
	while (node->cost > 0 && node->target->cost-- > 0)
	{
		if (node->top)
			ft_run_rotation(s1, s2, 2);
		else
			ft_run_reverse_rotation(s1, s2, 2);
		node->cost--;
	}
	while (node->cost--)
	{
		if (node->top)
			ft_run_rotation(s1, s2, 1);
		else
			ft_run_reverse_rotation(s1, s2, 1);
	}
	while (node->target->cost-- > 0)
	{
		if (node->top)
			ft_run_rotation(s1, s2, 0);
		else
			ft_run_reverse_rotation(s1, s2, 0);
	}
	ft_run_push(s1, s2, 0);
}

void	stack_index_cost(t_stack **stack)
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
