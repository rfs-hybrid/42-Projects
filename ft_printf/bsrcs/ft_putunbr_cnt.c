/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:39:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 19:37:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_string(char *s, t_flags flags, int *total)
{
	if (flags.minus)
	{
		ft_putstr_fd(s, 1);
		while ((*total)++ < flags.width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*total)++ < flags.width)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(s, 1);
	}
}

static void	ft_parse_prec(char *s, t_flags *flags, int *total)
{
	if (flags->minus)
	{
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
		*total = ft_strlen(s);
		while ((*total)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	*total = flags->width;
}

static void	ft_parse_unbr(char *s, t_flags *flags, int *total)
{
	if (flags->prec > -1 && flags->prec < flags->width && *total < flags->width)
	{
		if (flags->prec < *total)
			flags->prec = *total;
		ft_parse_prec(s, flags, total);
		return ;
	}
	else if (flags->prec > -1)
	{
		while ((*total)++ < flags->prec)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else if (flags->zero && !(flags->minus))
	{
		while ((*total)++ < flags->width)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(s, 1);
	}
	else
		ft_parse_string(s, *flags, total);
	(*total)--;
}

int	ft_putunbr_cnt(unsigned int n, t_flags *flags)
{
	char	*str;
	int		cnt;

	if (!n && flags->prec > -1)
		str = ft_strdup("");
	else
		str = ft_utoa_base(n, "0123456789", 10);
	cnt = ft_strlen(str);
	ft_parse_unbr(str, flags, &cnt);
	reset_flags(flags);
	return (free(str), cnt);
}
