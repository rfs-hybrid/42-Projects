/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:14:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 14:21:02 by maaugust         ###   ########.fr       */
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
	int	a = 11;
	int b = 3;
	int div = -1;
	int	mod = -1;

	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d == %d\n", a, b, div);
	printf("%d %% %d == %d\n", a, b, mod);
	return (0);
}
