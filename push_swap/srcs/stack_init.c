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

static void	update_final_pos(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node && node->next)
	{
		tmp = node->next;
		while (tmp)
		{
			if ((node->value > tmp->value && node->idx < tmp->idx)
				|| (node->value < tmp->value && node->idx > tmp->idx))
			{
				swap(&(node->idx), &(tmp->idx));
				tmp = node->next;
				continue ;
			}
			tmp = tmp->next;
		}
		node = node->next;
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
	update_final_pos(stack);
	ft_stack_prev_node_init(stack);
}
