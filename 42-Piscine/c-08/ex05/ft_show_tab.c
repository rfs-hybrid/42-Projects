/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:28:59 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/10 11:56:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write (1, &str[i], 1);
	write (1, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
	}
}
