/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:26:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 19:38:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

int	main(void)
{
	int	result;
	int	remainder;

	result = 0;
	remainder = 0;
	printf ("Before -> result = %d, remainder = %d\n", result, remainder);
	ft_div_mod(9, 2, &result, &remainder);
	printf ("After -> result = %d, remainder = %d\n", result, remainder);
}
