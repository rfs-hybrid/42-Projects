/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:12:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/02 21:15:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotation(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	rra(t_stack **a)
{
	reverse_rotation(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotation(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotation(a);
	reverse_rotation(b);
	ft_printf("rrr\n");
}
