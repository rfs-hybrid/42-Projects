/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:50:37 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 19:48:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	printf ("%d\n", ft_is_prime(-1));
	printf ("%d\n", ft_is_prime(1));
	printf ("%d\n", ft_is_prime(2));
	printf ("%d\n", ft_is_prime(5));
	printf ("%d\n", ft_is_prime(131));
	printf ("%d\n", ft_is_prime(192));
	printf ("%d\n", ft_is_prime(2147483647));
	printf ("%d\n", ft_is_prime(0));
}
