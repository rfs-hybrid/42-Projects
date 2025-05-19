/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:39:10 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 15:00:35 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	reset_flags(t_flags *flags)
{
	flags->minus = false;
	flags->plus = false;
	flags->space = false;
	flags->hash = false;
	flags->zero = false;
	flags->width = 0;
	flags->prec = -1;
}

void	update_flags(const char *s, t_flags *flags)
{
	if (!(flags->minus) && *s == '-')
		flags->minus = true;
	if (!(flags->plus) && *s == '+')
		flags->plus = true;
	if (!(flags->space) && *s == ' ')
		flags->space = true;
	if (!(flags->hash) && *s == '#')
		flags->hash = true;
	if (!(flags->zero) && flags->width == 0 && *s == '0')
		flags->zero = true;
	else if (flags->width == 0 && flags->prec < 0 && *s > '0' && *s <= '9')
	{
		while (*s >= '0' && *s <= '9')
			flags->width = flags->width * 10 + (*s++ - '0');
	}
	if (flags->prec < 0 && *s == '.')
	{
		flags->prec = 0;
		if (*(s + 1) >= '0' && *(s + 1) <= '9')
		{
			s++;
			while (*s >= '0' && *s <= '9')
				flags->prec = flags->prec * 10 + (*s++ - '0');
		}
	}
}

bool	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}
