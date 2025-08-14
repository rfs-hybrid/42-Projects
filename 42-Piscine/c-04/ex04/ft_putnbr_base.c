/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:26:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/03 19:18:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

unsigned long int	ft_abs(long	int nbr)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	return (nbr);
}

unsigned char	ft_is_base_valid(char *base)
{
	unsigned char	i;
	unsigned char	j;
	unsigned char	len;

	len = ft_strlen(base);
	if (len < 2 || *base == '+' || *base == '-')
		return (0);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_recursive(unsigned long int nbr, char *base, unsigned int len)
{
	if (nbr >= len)
	{
		ft_putnbr_recursive(nbr / len, base, len);
		nbr %= len;
	}
	write(1, &base[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned char	len;

	if (ft_is_base_valid(base))
	{
		len = ft_strlen(base);
		ft_putnbr_recursive(ft_abs(nbr), base, len);
	}
}
