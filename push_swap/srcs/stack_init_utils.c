/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:09:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/10 14:42:42 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_stack_is_sorted(t_stack *stack, bool is_rev)
{
	t_stack	*begin;

	if (!stack)
		return (false);
	begin = stack;
	while (begin != stack->next)
	{
		if ((!is_rev && stack->pos > stack->next->pos)
			|| (is_rev && stack->pos < stack->next->pos))
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_free_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
	words = NULL;
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;
	size_t	i;

	res = 0;
	i = 0;
	sign = 1;
	while (*(nptr + i) == ' ' || (*(nptr + i) >= '\t' && *(nptr + i) <= '\r'))
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(*(nptr + i)))
		res = res * 10 + ((*(nptr + i++)) - '0');
	return (res * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return ((*((unsigned char *)(s1 + i))) - (*((unsigned char *)(s2 + i))));
}
