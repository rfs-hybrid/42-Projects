/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:23:05 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 17:15:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 1)
		res *= nb--;
	return (res);
}

int	main(void)
{
	printf("!5  == %d\n", ft_iterative_factorial(5));
	printf("!-4 == %d\n", ft_iterative_factorial(-4));
	printf("!1  == %d\n", ft_iterative_factorial(1));
	printf("!0  == %d\n", ft_iterative_factorial(0));
	printf("!-1 == %d\n", ft_iterative_factorial(-1));
	printf("!2  == %d\n", ft_iterative_factorial(2));
}
