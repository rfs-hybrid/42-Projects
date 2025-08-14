/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:28:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 19:41:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	result;
	int	remainder;

	result = 0;
	remainder = 0;
	if (*b != 0)
	{
		result = *a / *b;
		remainder = *a % *b;
		*a = result;
		*b = remainder;
	}
}

int	main(void)
{
	int	a;
	int	b;

	a = 9;
	b = 2;
	printf("Before -> a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After -> a = %d, b = %d\n", a, b);
}
