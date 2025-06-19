/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:13:27 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 18:26:20 by maaugust         ###   ########.fr       */
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

void	ft_run_commands(t_stack **s1, t_stack **s2, t_stack *node)
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
