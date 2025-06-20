/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:09:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 20:13:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
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
