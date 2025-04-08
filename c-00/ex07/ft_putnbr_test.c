/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:46:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/25 10:32:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb, char cnt)
{
	char c;

	printf("\nRecursion no %c started\n", cnt);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		write (1, "2147483648", 10);
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10, cnt + 1);
			nb %= 10;
		}
		c = nb + '0';
		write(1, &c, 1);
		printf("\nRecursion no %c finished\n", cnt);
	}
}

int	main(void)
{
	ft_putnbr(1234, '1');
}
