/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:32:27 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/04 16:09:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

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
			ft_putnbr(nb / 10);
			nb %= 10;
		}
		c = nb + '0';
		write(1, &c, 1);
	}
}

int	main(void)
{
	ft_putnbr(1234);
}
