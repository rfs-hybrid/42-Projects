/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:51:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 23:28:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	ft_parse_string(char *s, t_flags flags, int *cnt, char c)
{
	if (flags.minus)
	{
		ft_print_hash(flags, c);
		ft_putstr_fd(s, 1);
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
		ft_print_hash(flags, c);
		ft_putstr_fd(s, 1);
	}
}

static void	ft_parse_prec(char *s, t_flags *flags, int *cnt, char c)
{
	if (flags->minus)
	{
		ft_print_hash(*flags, c);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
		while ((flags->prec)++ < flags->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		if (*cnt < flags->prec)
			*cnt = flags->prec;
		while ((*cnt)++ < flags->width)
			ft_putchar_fd(' ', 1);
		ft_print_hash(*flags, c);
		*cnt = ft_strlen(s) + 2 * ((int) flags->hash);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	*cnt = flags->width;
}

static void	ft_parse_hex(char *s, t_flags *flags, int *cnt, char c)
{
	if (flags->prec > -1 && flags->prec < flags->width && *cnt < flags->width)
	{
		if (flags->prec < *cnt)
			flags->prec = *cnt;
		ft_parse_prec(s, flags, cnt, c);
		return ;
	}
	else if (flags->prec > -1)
	{
		ft_print_hash(*flags, c);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else if (flags->zero && !(flags->minus))
	{
		ft_print_hash(*flags, c);
		while ((*cnt)++ < flags->width)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else
		ft_parse_string(s, *flags, cnt, c);
	(*cnt)--;
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
	if (!str)
		return (-1);
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
