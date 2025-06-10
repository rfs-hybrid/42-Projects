/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:01:20 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 14:31:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*split_to_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 1;
	stack = NULL;
	while (*argv)
	{
		new = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!new)
		{
			ft_stackclear(&stack);
			ft_print_error();
		}
		new->pos = i++;
		new->value = ft_atoi(*argv);
		new->next = NULL;
		ft_stackadd_back(&stack, new);
		argv++;
	}
	return (stack);
}

t_stack	*ft_argv_to_stack(char **argv)
{
	t_stack	*stack;

	argv++;
	validation(argv, true);
	stack = split_to_stack(argv);
	return (stack);
}
