/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:10:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/25 15:05:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_cnt(int n)
{
	int		cnt;

	if (n == -2147483648)
		return (ft_putstr_cnt("-2147483648"));
	cnt = 0;
	if (n < 0)
		cnt += ft_putchar_cnt('-');
	n *= (n > 0) - (n < 0);
	cnt += ft_putnbr_base(n, "0123456789", 10);
	return (cnt);
}
