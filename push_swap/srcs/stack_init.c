/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:38:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 17:41:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	stack_prev_node_init(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	tmp = *stack;
	tmp->prev = last;
	tmp = tmp->next;
	while (tmp != *stack)
	{
		last = last->next;
		tmp->prev = last;
		tmp = tmp->next;
	}
}

void	ft_stack_init(t_stack **stack, int argc, char **argv)
{
	if (argc == 2)
		*stack = ft_string_to_stack(argv[1]);
	else
		*stack = ft_argv_to_stack(argv);
	if (!*stack)
		ft_print_error();
	stack_prev_node_init(stack);
	ft_stack_reset_indexes(stack);
}
