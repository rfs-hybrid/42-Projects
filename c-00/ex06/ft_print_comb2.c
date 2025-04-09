/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/24 16:01:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_digits(char c)
{
	char	digit1;
	char	digit0;

	digit1 = (c / 10) + '0';
	digit0 = (c % 10) + '0';
	write (1, &digit1, 1);
	write (1, &digit0, 1);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_write_digits(a);
			write (1, " ", 1);
			ft_write_digits(b);
			if (a != 98)
				write (1, ", ", 2);
			b++;
		}
		a++;
	}
}
