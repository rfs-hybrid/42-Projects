/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:59:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 16:40:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	rt;

	if (nb < 0)
		return (0);
	rt = 1;
	while (rt * rt <= nb && rt * rt > 0)
	{
		if (rt * rt == nb)
			return (rt);
		rt++;
	}
	return (0);
}

int	main(void)
{
	printf("sqrt(-1) == %d\n", ft_sqrt(-1));
	printf("sqrt(24) == %d\n", ft_sqrt(24));
	printf("sqrt(25) == %d\n", ft_sqrt(25));
	printf("sqrt(9) == %d\n", ft_sqrt(9));
	printf("sqrt(8) == %d\n", ft_sqrt(8));
	printf("sqrt(0) == %d\n", ft_sqrt(0));
}
