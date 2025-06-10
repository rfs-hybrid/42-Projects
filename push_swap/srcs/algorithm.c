/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 17:22:50 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_algorithm(t_stack **a, t_stack **b, t_lis lis, int max)
{
	int	i;

	ft_stack_lis_init(a, b, lis, max);
	i = -1;
	ft_putstr_fd("\nSTACK A: ", 1);
	while (++i < lis.size)
	{
		ft_printf ("%d ", (*a)->pos);
		*a = (*a)->next;
	}
	ft_putchar_fd('\n', 1);
	i = -1;
	ft_putendl_fd("----------------------------------------------", 1);
	ft_putstr_fd("STACK B: ", 1);
	while (++i < max - lis.size)
	{
		ft_printf ("%d ", (*b)->pos);
		*b = (*b)->next;
	}
	ft_putchar_fd('\n', 1);
}

void	three_num_algorithm(t_stack **s, bool check)
{
	if ((*s)->prev == (*s)->next)
		ra(s, check);
	else if ((*s)->pos < (*s)->prev->pos && (*s)->pos < (*s)->next->pos)
	{
		sa(s, check);
		ra(s, check);
	}
	else if ((*s)->pos < (*s)->prev->pos)
		sa(s, check);
	else if ((*s)->pos < (*s)->next->pos)
		rra(s, check);
	else if ((*s)->prev->pos > (*s)->next->pos)
		ra(s, check);
	else
	{
		sa(s, check);
		rra(s, check);
	}
}
