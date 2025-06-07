/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:40:15 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/07 15:01:00 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack	*tmp1;
	// t_stack	*tmp2;
	
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (1);
	stack_init(&a, argc, argv);
	if (!ft_stack_is_sorted(a))
		push_swap(&a, &b, ft_stack_maxindex(a));
	int	i = 5;
	tmp1 = a;
	// tmp2 = b;
	while (i--)
	{
		ft_printf("a -> %d\n", tmp1->value);
	// 	ft_printf("b%d : %d\n", tmp2->value, tmp2->pos);
		tmp1 = tmp1->next;
	// 	tmp2 = tmp2->next;
	}
	// ft_printf("---------------------------------------------------------------\n");
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// tmp = a;
	// i = 5;
	// while (i--)
	// {
	// 	ft_printf("%d : %d\n", tmp->value, tmp->pos);
	// 	tmp = tmp->next;
	// }
	// ft_printf("---------------------------------------------------------------\n");
	// rra(&a);
	// tmp = a;
	// i = 7;
	// while (i--)
	// {
	// 	ft_printf("%d : %d -> %d\n", tmp->value, tmp->current_i, tmp->final_i);
	// 	tmp = tmp->next;
	// }
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
