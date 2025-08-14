/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:39:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 12:45:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>

int	main(void)
{
	int	num = 5;
	printf("%d\n", ft_recursive_factorial(num));
}
