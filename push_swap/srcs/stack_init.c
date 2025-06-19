/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:38:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/18 16:53:52 by maaugust         ###   ########.fr       */
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

static void	find_final_index(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *stack;
	while (node && node->next)
	{
		tmp = node->next;
		while (tmp)
		{
			if ((node->val > tmp->val && node->idx < tmp->idx)
				|| (node->val < tmp->val && node->idx > tmp->idx))
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

static void	normalize_values(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		node->val = node->idx;
		node = node->next;
	}
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
	find_final_index(stack);
	normalize_values(stack);
	stack_prev_node_init(stack);
}
