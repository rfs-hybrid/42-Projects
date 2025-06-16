/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	find_cheapest_num(t_stack **a, t_stack **b)
// {

// }

void	ft_lis_algorithm(t_stack **a, t_stack **b, t_lis lis)
{
	int	i;

	ft_stack_lis_init(a, b, lis);
	i = -1;
	ft_putendl_fd("\n--------------------------------------------------------------------------------------------------", 1);
	ft_putstr_fd("STACK A: ", 1);
	while (++i < lis.size)
	{
		ft_printf ("%d ", (*a)->idx);
		*a = (*a)->next;
	}
	ft_putchar_fd('\n', 1);
	i = -1;
	ft_putendl_fd("--------------------------------------------------------------------------------------------------", 1);
	ft_putstr_fd("STACK B: ", 1);
	while (++i < ft_stack_size(*b))
	{
		ft_printf ("%d ", (*b)->idx);
		*b = (*b)->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("--------------------------------------------------------------------------------------------------\n", 1);
}

void	ft_three_num_algorithm(t_stack **stack, bool check)
{
	if ((*stack)->prev == (*stack)->next)
	{
		sa(stack, check);
		return ;
	}
	if (!((*stack)->prev->val < (*stack)->val
		&& (*stack)->prev->val > (*stack)->next->val)
		&& !((*stack)->val < (*stack)->next->val
		&& (*stack)->val > (*stack)->prev->val))
		sa(stack, check);
	if (!ft_stack_is_sorted(*stack, false))
	{
		if ((*stack)->val > (*stack)->next->val
			&& (*stack)->prev->val > (*stack)->next->val)
			ra(stack, check);
		else
			rra(stack, check);
	}
}
