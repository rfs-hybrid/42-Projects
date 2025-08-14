/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:30 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 17:14:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 3)
		return (2);
	i = 2;
	while (nb >= 3)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 2;
		}
		else if (i == nb - 1)
			return (nb);
		else
			i++;
	}
	return (2);
}

#include <stdio.h>

int	main(void)
{
	printf ("%d\n", ft_find_next_prime(143));
	printf ("%d\n", ft_find_next_prime(-1000));
	printf ("%d\n", ft_find_next_prime(0));
	printf ("%d\n", ft_find_next_prime(1));
	printf ("%d\n", ft_find_next_prime(2));
	printf ("%d\n", ft_find_next_prime(3));
	printf ("%d\n", ft_find_next_prime(5));
	printf ("%d\n", ft_find_next_prime(12));
	printf ("%d\n", ft_find_next_prime(14));
}
