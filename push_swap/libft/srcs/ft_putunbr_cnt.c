/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:39:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 23:37:00 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_string(char *s, t_flags flags, int *cnt)
{
	if (flags.minus)
	{
		ft_putstr_fd(s, 1);
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*cnt)++ < flags.width)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(s, 1);
	}
}

static void	ft_parse_prec(char *s, t_flags *flags, int *cnt)
{
	if (flags->minus)
	{
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
		*cnt = ft_strlen(s);
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	*cnt = flags->width;
}

static void	ft_parse_unbr(char *s, t_flags *flags, int *cnt)
{
	if (flags->prec > -1 && flags->prec < flags->width && *cnt < flags->width)
	{
		if (flags->prec < *cnt)
			flags->prec = *cnt;
		ft_parse_prec(s, flags, cnt);
		return ;
	}
	else if (flags->prec > -1)
	{
		while ((*cnt)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else if (flags->zero && !(flags->minus))
	{
		while ((*cnt)++ < flags->width)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else
		ft_parse_string(s, *flags, cnt);
	(*cnt)--;
}

int	ft_putunbr_cnt(unsigned int n, t_flags *flags)
{
	char	*str;
	int		cnt;

	if (!n && flags->prec > -1)
		str = ft_strdup("");
	else
		str = ft_utoa_base(n, "0123456789", 10);
	if (!str)
		return (-1);
	cnt = ft_strlen(str);
	ft_parse_unbr(str, flags, &cnt);
	reset_flags(flags);
	return (free(str), cnt);
}
