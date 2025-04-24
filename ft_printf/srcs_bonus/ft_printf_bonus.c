/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/23 13:06:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_check_arg(char c, va_list args, t_flags flags)
{
	(void) flags;
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
	t_flags flags;

	total = 0;
	initialize_flags(&flags);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			total += ft_check_arg(*s, args, flags);
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

static void	initialize_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->star = 0;
}

int	ft_printf(const char *s, ...)
{
	int		total;
	va_list	args;
	t_flags	flags;

	total = 0;
	if (!s)
		return (total);
	va_start(args, s);
	total = ft_parse_string(s, args);
	va_end(args);
	return (total);
}

// int	main(void)
// {
// 	int	res1;
// 	int	res2;
// 	res1 = printf("printf1 == %     -      7d done\n", 123);
// 	res2 = ft_printf("printf2 == %x    %x    %x     %x     %x     %x     %x     %x    %x      %x     %x     %x     %x     %x\n", 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700);
// 	printf("res1 == %d\n", res1);
// 	printf("res2 == %d\n", res2);
// 	return (0);
// }
