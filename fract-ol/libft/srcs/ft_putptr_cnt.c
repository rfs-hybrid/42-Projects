/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:20:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 23:32:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_cnt(void *s, t_flags *flags)
{
	unsigned long	addr;
	char			*str;
	char			*tmp;
	int				cnt;

	if (!s)
		return (ft_putstr_cnt("(nil)", flags));
	addr = (unsigned long) s;
	tmp = ft_utoa_base(addr, "0123456789abcdef", 16);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	if (!str)
		return (-1);
	cnt = ft_putstr_cnt(str, flags);
	return (free(str), cnt);
}
