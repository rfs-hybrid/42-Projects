/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 19:36:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_null(t_flags *flags, int *total)
{
	if (flags->prec < 0 || flags->prec > 5)
	{
		*total = 6;
		if (flags->minus)
		{
			ft_putstr_fd("(null)", 1);
			while ((*total)++ < flags->width)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while ((*total)++ < flags->width)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd("(null)", 1);
		}
	}
	else
	{
		while ((*total)++ < flags->width)
			ft_putchar_fd(' ', 1);
	}
	(*total)--;
}

static void	ft_parse_string(char *s, t_flags *flags, int *total)
{
	char	*str;

	if ((flags->prec >= 0) && (*total > flags->prec))
	{
		*total = flags->prec;
		str = ft_substr(s, 0, *total);
	}
	else
		str = ft_strdup(s);
	if (flags->minus)
	{
		ft_putstr_fd(str, 1);
		while ((*total)++ < flags->width)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((*total)++ < flags->width)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
	}
	free(str);
	(*total)--;
}

int	ft_putstr_cnt(char *s, t_flags *flags)
{
	int	cnt;

	if (!s)
	{
		cnt = 0;
		ft_parse_null(flags, &cnt);
	}
	else
	{
		cnt = ft_strlen(s);
		ft_parse_string(s, flags, &cnt);
	}
	reset_flags(flags);
	return (cnt);
}
