/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:10:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/23 13:05:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_cnt(int n)
{
	int		cnt;

	if (n == INT_MIN_VAL)
		return (ft_putstr_cnt("-2147483648"));
	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchar_cnt('-');
		n *= -1;
	}
	cnt += ft_putnbr_base(n, HEX_LOWER, DEC_LEN);
	return (cnt);
}
