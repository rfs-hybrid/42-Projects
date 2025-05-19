/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:20:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/25 15:00:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_cnt(void *s)
{
	unsigned long long	addr;

	if (!s)
		return (ft_putstr_cnt("(nil)"));
	addr = (unsigned long long) s;
	return (ft_putstr_cnt("0x") + ft_putnbr_base(addr, "0123456789abcdef", 16));
}
