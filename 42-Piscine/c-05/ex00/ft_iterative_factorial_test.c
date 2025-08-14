/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:32:24 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 19:34:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		res = 0;
	else
	{
		res = 1;
		while (nb > 1)
		{
			res *= nb;
			nb--;
		}
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	int	num = 5;
	printf ("%d! == %d\n", num, ft_iterative_factorial(num));
}
