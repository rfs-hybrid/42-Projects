/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:51:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 19:38:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_hash(t_flags flags, char c)
{
	if (flags.hash)
	{
		if (c == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
}

static void	ft_parse_string(char *s, t_flags flags, int *total, char c)
{
	if (flags.minus)
	{
		ft_print_hash(flags, c);
		ft_putstr_fd(s, 1);
		while ((*total)++ < flags.width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*total)++ < flags.width)
			ft_putchar_fd(' ', 1);
		ft_print_hash(flags, c);
		ft_putstr_fd(s, 1);
	}
}

static void	ft_parse_prec(char *s, t_flags *flags, int *total, char c)
{
	if (flags->minus)
	{
		ft_print_hash(*flags, c);
		while ((*total)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
		while ((flags->prec)++ < flags->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		if (*total < flags->prec)
			*total = flags->prec;
		while ((*total)++ < flags->width)
			ft_putchar_fd(' ', 1);
		ft_print_hash(*flags, c);
		*total = ft_strlen(s) + 2 * ((int) flags->hash);
		while ((*total)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	*total = flags->width;
}

static void	ft_parse_hex(char *s, t_flags *flags, int *total, char c)
{
	if (flags->prec > -1 && flags->prec < flags->width && *total < flags->width)
	{
		if (flags->prec < *total)
			flags->prec = *total;
		ft_parse_prec(s, flags, total, c);
		return ;
	}
	else if (flags->prec > -1)
	{
		ft_print_hash(*flags, c);
		while ((*total)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else if (flags->zero && !(flags->minus))
	{
		ft_print_hash(*flags, c);
		while ((*total)++ < flags->width)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else
		ft_parse_string(s, *flags, total, c);
	(*total)--;
}

int	ft_puthex_cnt(long nbr, t_flags *flags, char c)
{
	char	*str;
	int		cnt;

	if (!nbr && flags->prec > -1)
		str = ft_strdup("");
	else if (c == 'x')
		str = ft_utoa_base((unsigned long) nbr, "0123456789abcdef", 16);
	else
		str = ft_utoa_base((unsigned long) nbr, "0123456789ABCDEF", 16);
	cnt = ft_strlen(str);
	if (nbr == 0)
		flags->hash = false;
	if (flags->hash)
	{
		cnt += 2;
		if (flags->prec > -1)
			flags->prec += 2;
	}
	ft_parse_hex(str, flags, &cnt, c);
	reset_flags(flags);
	return (free(str), cnt);
}
