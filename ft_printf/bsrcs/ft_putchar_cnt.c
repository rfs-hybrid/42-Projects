/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:07:18 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/21 15:41:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_cnt(char c, t_flags *flags)
{
	int	cnt;

	cnt = 1;
	if (flags->minus)
	{
		ft_putchar_fd(c, 1);
		while (cnt++ < flags->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (cnt++ < flags->width)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
	cnt--;
	reset_flags(flags);
	return (cnt);
}
