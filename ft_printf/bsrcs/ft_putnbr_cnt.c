/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:10:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/21 15:41:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_sign(t_flags flags, bool neg)
{
	if (neg)
		ft_putchar_fd('-', 1);
	else if (flags.plus)
		ft_putchar_fd('+', 1);
	else if (flags.space)
		ft_putchar_fd(' ', 1);
}

static void	ft_parse_prec(char *s, t_flags *flags, int *cnt, bool neg)
{
	if (flags->minus)
	{
		ft_print_sign(*flags, neg);
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
		ft_print_sign(*flags, neg);
		*cnt = ft_strlen(s) + (neg || flags->plus || flags->space);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	*cnt = flags->width;
}

static void	ft_parse_string(char *s, t_flags flags, int *cnt, bool neg)
{
	if (flags.minus)
	{
		ft_print_sign(flags, neg);
		ft_putstr_fd(s, 1);
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
		ft_print_sign(flags, neg);
		ft_putstr_fd(s, 1);
	}
}

static void	ft_parse_nbr(char *s, t_flags *flags, int *cnt, bool neg)
{
	if (flags->prec > -1 && flags->prec < flags->width && *cnt < flags->width)
	{
		if (flags->prec < *cnt)
			flags->prec = *cnt;
		ft_parse_prec(s, flags, cnt, neg);
		return ;
	}
	else if (flags->prec > -1)
	{
		ft_print_sign(*flags, neg);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else if (flags->zero && !(flags->minus))
	{
		ft_print_sign(*flags, neg);
		while ((*cnt)++ < flags->width)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else
		ft_parse_string(s, *flags, cnt, neg);
	(*cnt)--;
}

int	ft_putnbr_cnt(int n, t_flags *flags)
{
	char	*str;
	long	nbr;
	int		cnt;

	nbr = (long) n;
	nbr *= (nbr > 0) - (nbr < 0);
	if (!nbr && flags->prec > -1)
		str = ft_strdup("");
	else
		str = ft_utoa_base((unsigned long) nbr, "0123456789", 10);
	if (!str)
		return (-1);
	cnt = ft_strlen(str);
	if ((n < 0) || flags->plus || flags->space)
	{
		cnt++;
		if (flags->prec > -1)
			(flags->prec)++;
	}
	ft_parse_nbr(str, flags, &cnt, (n < 0));
	reset_flags(flags);
	return (free(str), cnt);
}
