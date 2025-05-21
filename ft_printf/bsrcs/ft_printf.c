/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/21 15:41:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_check_arg(char c, va_list args, t_flags *flags)
{
	if (c == 'c')
		return (ft_putchar_cnt(va_arg(args, int), flags));
	else if (c == 's')
		return (ft_putstr_cnt(va_arg(args, char *), flags));
	else if (c == 'p')
		return (ft_putptr_cnt(va_arg(args, void *), flags));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_cnt(va_arg(args, int), flags));
	else if (c == 'u')
		return (ft_putunbr_cnt(va_arg(args, unsigned int), flags));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_cnt((long)(va_arg(args, unsigned int)), flags, c));
	else if (c == '%')
		return (write(1, "%%", 1));
	return (-1);
}

static void	ft_parse_str(const char *s, va_list args, t_flags *flags, int *cnt)
{
	int	n;

	while (*s)
	{
		if (*s == '%')
		{
			s++;
			while (*s && !(is_specifier(*s)))
				update_flags(s++, flags);
			n = ft_check_arg(*s, args, flags);
			if (n < 0)
			{
				*cnt = -1;
				return ;
			}
			*cnt += n;
			reset_flags(flags);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			(*cnt)++;
		}
		s++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		cnt;
	va_list	args;
	t_flags	flags;

	cnt = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	reset_flags(&flags);
	ft_parse_str(s, args, &flags, &cnt);
	va_end(args);
	return (cnt);
}
