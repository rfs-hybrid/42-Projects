/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:40:15 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		size;
	
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (0);
	ft_stack_init(&a, argc, argv);
	if (!ft_stack_is_sorted(a, false))
	{
		size = ft_stack_size(a);
		if (size <= 3)
			ft_three_num_algorithm(&a, false);
		else
			ft_push_swap(&a, &b, size);
	}
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
