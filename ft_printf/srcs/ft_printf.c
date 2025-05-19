/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 15:56:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_check_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_cnt(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr_cnt(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr_cnt(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_cnt(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr_cnt(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_cnt(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_cnt('%'));
	else
		return (ft_putchar_cnt(c));
}

static int	ft_parse_string(const char *s, va_list args)
{
	int	total;

	total = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			total += ft_check_arg(*s, args);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			total++;
		}
		s++;
	}
	return (total);
}

int	ft_printf(const char *s, ...)
{
	int		total;
	va_list	args;

	total = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	total = ft_parse_string(s, args);
	va_end(args);
	return (total);
}

// int	main(void)
// {
// 	long n = LONG_MIN;
// 	// char *str;
// 	int		res1;
// 	int		res2;

// 	// str = NULL;
// 	res1 = printf("printf1 == %lx done\n", n);
// 	res2 = ft_printf("printf2 == %x done\n", n);
// 	printf("res1 == %d\n", res1);
// 	printf("res2 == %d\n", res2);
// 	return (0);
// }
