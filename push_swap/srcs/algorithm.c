/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:15:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/09 19:40:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    lis_algorithm(t_stack **a, t_stack **b, t_stack *lis)
{

}
