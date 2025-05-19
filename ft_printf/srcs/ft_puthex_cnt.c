/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:51:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/25 15:00:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_cnt(unsigned int nbr, char c)
{
	if (c == 'x')
		return (ft_putnbr_base(nbr, "0123456789abcdef", 16));
	return (ft_putnbr_base(nbr, "0123456789ABCDEF", 16));
}
