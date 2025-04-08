/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:31:18 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 17:09:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	main(void)
{
	printf("!5  == %d\n", ft_recursive_factorial(5));
	printf("!-4 == %d\n", ft_recursive_factorial(-4));
	printf("!1  == %d\n", ft_recursive_factorial(1));
	printf("!0  == %d\n", ft_recursive_factorial(0));
	printf("!-1  == %d\n", ft_recursive_factorial(-1));
}
