/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/14 19:05:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		res;
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
