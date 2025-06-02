/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:59:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/02 21:17:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_stack **a)
{
	rotation(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotation(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotation(a);
	rotation(b);
	ft_printf("rr\n");
}
