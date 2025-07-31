/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:41:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/31 15:00:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

static void	skip_whitespace(t_reader *r)
{
	char	c;

	while (1)
	{
		c = next_char(r);
		if (c == '\0')
			break ;
		if (c != ' ' && (c < '\t' || c > '\r'))
		{
			unread_char(r, c);
			break ;
		}
	}
}

static int	hex_char_to_int(char c)
{
	if (c >= 0 && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	return (-1);
}

static int	read_int(t_reader *r)
{
	int		res;
	int		sign;
	char	c;

	res = 0;
	sign = 1;
	skip_whitespace(r);
	c = next_char(r);
	if (c == '-')
	{
		sign *= -1;
		c = next_char(r);
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + (c - '0');
		c = next_char(r);
	}
	if (c != '\0')
		unread_char(r, c);
	return (res * sign);
}

static unsigned int	read_hex(t_reader *r)
{
	unsigned int	res;
	int				val;
	char			c;
	char			tmp;

	res = 0;
	skip_whitespace(r);
	c = next_char(r);
	if (c == '0')
	{
		tmp = next_char(r);
		if (tmp != 'x' && tmp != 'X')
		{
			unread_char(r, tmp);
			unread_char(r, c);
		}
	}
	else
		unread_char(r, c);
	while(true)
	{
		c = next_char(r);
		val = hex_char_to_int(c);
		if (val < 0)
			break ;
		res = res * 16 + val;
	}
	if (c != '\0')
		unread_char(r, c);
	return (res);
}

static void	parse_format(va_list args, const char *s, int *total)
{
	t_reader		r;
	char			*cp;
	char			*sp;
	int				*ip;
	unsigned int	*xp;
	char			c;
	int				i;

	r.has_peek = false;
	r.peek_char = '\0';
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'c')
			{
				cp = va_arg(args, char *);
				skip_whitespace(&r);
				*cp = next_char(&r);
				(*total)++;
			}
			if (*s == 's')
			{
				i = 0;
				sp = va_arg(args, char *);
				skip_whitespace(&r);
				c = next_char(&r);
				while (c != '\0' && c != ' ' && !(c >= '\t' && c <= '\r'))
				{
					sp[i++] = c;
					c = next_char(&r);
				}
				sp[i] = '\0';
				if (c != '\0')
					unread_char(&r, c);
				(*total)++;
			}
			if (*s == 'd')
			{
				ip = va_arg(args, int *);
				*ip = read_int(&r);
				(*total)++;
			}
			if (*s == 'x' || *s == 'X')
			{
				xp = va_arg(args, unsigned int *);
				*xp = read_hex(&r);
				(*total)++;
			}
		}
		s++;
	}
}

int	ft_scanf(const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	parse_format(args, format, &total);
	va_end(args);
	return (total);
}
