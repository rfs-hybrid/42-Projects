/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:20:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/22 13:53:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_cnt(void *s)
{
	unsigned long long	addr;
	char				*base;
	size_t				len;
	int					cnt;

	if (!s)
		return (ft_putstr_cnt("(nil)"));
	addr = (unsigned long long) s;
	base = ft_strdup("0123456789abcdef");
	len = ft_strlen(base);
	cnt = ft_putstr_cnt("0x") + ft_putnbr_base(addr, base, len);
	free (base);
	return (cnt);
}
