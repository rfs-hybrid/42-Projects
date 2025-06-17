/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 17:25:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_stack_lis_numbers(t_stack **a, t_lis lis)
{
	t_stack	*current;

	current = (*a)->prev;
	while (lis.size)
	{
		if (current->val == lis.arr[lis.size - 1])
		{
			current->lis = true;
			current->cost = INT_MAX / 2;
			lis.size--;	
		}
		current = current->prev;
	}
}

static int	*stack_to_array(t_stack *s, int max)
{
	int	*arr;
	int	i;

	arr = (int *) ft_calloc(max, sizeof(int));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < max)
	{
		arr[i] = s->val;
		s = s->next;
	}
	return (arr);
}

static void	three_num_algorithm(t_stack **stack)
{
	if ((*stack)->prev == (*stack)->next)
	{
		ft_run_swap(stack, NULL, 0);
		return ;
	}
	if (!((*stack)->prev->val < (*stack)->val
		&& (*stack)->prev->val > (*stack)->next->val)
		&& !((*stack)->val < (*stack)->next->val
		&& (*stack)->val > (*stack)->prev->val))
		ft_run_swap(stack, NULL, 0);
	if (!ft_stack_is_sorted(*stack, false))
	{
		if ((*stack)->val > (*stack)->next->val
			&& (*stack)->prev->val > (*stack)->next->val)
			ft_run_rotation(stack, NULL, 0);
		else
			ft_run_reverse_rotation(stack, NULL, 0);
	}
}

void	ft_push_swap(t_stack **a, t_stack **b, int size)
{
	t_lis	lis;
	int		*a_array;

	if (size <= 3)
	{
		three_num_algorithm(a);
		return ;
	}
	if (ft_stack_is_sorted(*a, true))
		ft_run_swap(a, NULL, 0);
	a_array = stack_to_array(*a, size);
	lis.arr = ft_lis_sequence(a_array, size, &(lis.size));
	free (a_array);
	if (!lis.arr)
	{
		ft_stackclear(a);
		ft_print_error();
	}
	update_stack_lis_numbers(a, lis);
	ft_lis_algorithm(a, b, lis);
	free(lis.arr);
}
