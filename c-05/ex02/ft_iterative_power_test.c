/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:30:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 19:37:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	nbr = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power > 0)
		nb *= nbr;
	return (nb);
}

#include <stdio.h>

int	main(void)
{
	int	num = -4;
	int power = 5;
	printf("%d\n", ft_iterative_power(num, power));
}
