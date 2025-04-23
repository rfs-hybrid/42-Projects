/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/21 18:37:16 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_cnt(char *s)
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (*(s + cnt))
			ft_putchar_fd(*(s + cnt++), 1);
	}
	else
	{
		ft_putstr_fd("(null)", 1);
		cnt = 6;
	}
	return (cnt);
}
