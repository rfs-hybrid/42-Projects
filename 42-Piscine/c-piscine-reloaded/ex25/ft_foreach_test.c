/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:01:42 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 21:10:17 by maaugust         ###   ########.fr       */
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
			ft_putnbr(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = -1;
	while (++i < length)
	{
		f(tab[i]);
		write (1, "\n", 1);
	}
}

int	main(void)
{
	int arr[5] = {78241, -2184, 21, 36, -2147483648};
	ft_foreach(arr, 5, &ft_putnbr);
}
