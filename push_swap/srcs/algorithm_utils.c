/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	find_cheapest(t_stack **s1, t_stack **s2)
{
	stack_index_cost(s1);
	stack_index_cost(s2);

}

void	ft_stack_lis_sort(t_stack **a, t_stack **b, t_lis lis)
{
	while (ft_stack_size(*a) != lis.size && !ft_stack_is_semi_sorted(*a, false))
	{
		if (!((*a)->lis) && ft_stack_size(*b) < 2)	
			pb(a, b, false);
		else if (!((*a)->lis))
		{

		}
		else
		{

		}
		ft_stack_reset_indexes(a);
		ft_stack_reset_indexes(b);
	}
}
