/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:02:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/21 15:42:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_numlen(unsigned long nbr, size_t base_len)
{
	int	len;

	len = 0;
	while (nbr >= (unsigned long) base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long nbr, char *base, size_t base_len)
{
	char	*str;
	int		len;

	len = 1;
	len += ft_numlen(nbr, base_len);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = *(base + (nbr % base_len));
		nbr /= base_len;
	}
	return (str);
}
