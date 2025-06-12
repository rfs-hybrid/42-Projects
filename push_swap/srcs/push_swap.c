/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:57:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/12 21:16:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *s, int max)
{
	int	*arr;
	int	i;

	arr = (int *) ft_calloc(max, sizeof(int));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < max)
	{
		arr[i] = s->idx;
		s = s->next;
	}
	return (arr);
}

void	ft_push_swap(t_stack **a, t_stack **b, int size)
{
	t_lis	lis;
	int		*a_array;
	(void)	b;

	if (ft_stack_is_sorted(*a, true))
		sa(a, false);
	a_array = stack_to_array(*a, size);
	lis.arr = ft_lis_sequence(a_array, size, &(lis.size));
	free (a_array);
	if (!lis.arr)
	{
		ft_stackclear(a);
		ft_print_error();
	}
	lis.mid = lis.arr[lis.size / 2];
	ft_lis_algorithm(a, b, lis);
	free(lis.arr);
}
