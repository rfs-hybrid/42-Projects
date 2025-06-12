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
	int	total;

	total = ft_stack_lis_init(a, b, lis);
	ft_printf("\ntotal commands = %d", total);
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

void	ft_three_num_algorithm(t_stack **s, bool check)
{
	if ((*s)->prev == (*s)->next)
	{
		sa(s, check);
		return ;
	}
	if (!((*s)->prev->idx < (*s)->idx && (*s)->prev->idx > (*s)->next->idx)
		&& !((*s)->idx < (*s)->next->idx && (*s)->idx > (*s)->prev->idx))
		sa(s, check);
	if (!ft_stack_is_sorted(*s, false))
	{
		if ((*s)->idx > (*s)->next->idx	&& (*s)->prev->idx > (*s)->next->idx)
			ra(s, check);
		else
			rra(s, check);
	}
}
