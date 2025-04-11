/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:34:24 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/11 14:17:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	n_digits;

	n_digits = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		n_digits++;
	}
	if (n < 0)
		n_digits++;
	return (n_digits);
}

char	*store_number(char *str, int n, size_t len)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = len;
	if (n < 0)
	{
		*str = '-';
		n *= -1;
		max--;
	}
	while (i < max)
	{
		*(str + (len - 1 - i++)) = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = count_digits(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memmove(str, "-2147483648", len);
		return (str);
	}
	str = store_number(str, n, len);
	return (str);
}
