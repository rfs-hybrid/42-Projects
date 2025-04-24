/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:02:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/24 14:30:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long nbr, char *base, size_t len)
{
	int	cnt;

	cnt = 0;
	if (nbr >= (unsigned long long) len)
		cnt += ft_putnbr_base(nbr / (unsigned long long) len, base, len);
	return (cnt + ft_putchar_cnt(*(base + (nbr % (unsigned long long) len))));
}
