/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:40:15 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/02 21:17:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*tmp;
	// t_stack *b;
	
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (1);
	stack_init(&a, argc, argv);
	if (!is_sorted(a))
		ft_printf("FALSE\n");
	else
		ft_printf("TRUE\n");
	int	i = 7;
	tmp = a;
	while (i--)
	{
		ft_printf("%d : %d -> %d\n", tmp->value, tmp->current_i, tmp->final_i);
		tmp = tmp->next;
	}
	ft_printf("---------------------------------------------------------------\n");
	rra(&a);
	tmp = a;
	i = 7;
	while (i--)
	{
		ft_printf("%d : %d -> %d\n", tmp->value, tmp->current_i, tmp->final_i);
		tmp = tmp->next;
	}
	ft_printf("---------------------------------------------------------------\n");
	rra(&a);
	tmp = a;
	i = 7;
	while (i--)
	{
		ft_printf("%d : %d -> %d\n", tmp->value, tmp->current_i, tmp->final_i);
		tmp = tmp->next;
	}
	ft_stackclear(&a);
	return (0);
}
