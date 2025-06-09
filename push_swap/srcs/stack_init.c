/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:38:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/09 18:53:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	prev_node_init(t_stack **a)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *a;
	while (last->next)
		last = last->next;
	last->next = *a;
	tmp = *a;
	tmp->prev = last;
	tmp = tmp->next;
	while (tmp != *a)
	{
		last = last->next;
		tmp->prev = last;
		tmp = tmp->next;
	}
}

static void	update_final_pos(t_stack **a)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *a;
	while (node && node->next)
	{
		tmp = node->next;
		while (tmp)
		{
			if ((node->value > tmp->value && node->pos < tmp->pos)
				|| (node->value < tmp->value && node->pos > tmp->pos))
			{
				ft_swap(&(node->pos), &(tmp->pos));
				tmp = node->next;
				continue ;
			}
			tmp = tmp->next;
		}
		node = node->next;
	}
}

void	stack_init(t_stack **a, int argc, char **argv)
{
	if (argc == 2)
		*a = string_to_stack(argv[1]);
	else
		*a = argv_to_stack(argv);
	if (!*a)
		print_error();
	update_final_pos(a);
	prev_node_init(a);
}
