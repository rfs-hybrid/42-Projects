/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:11:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/19 19:22:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_parse_string(const char *s, va_list args, t_flags *flags)
{
	int	total;

	total = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			while (!(is_specifier(*s)))
			{
				update_flags(s, flags);
				s++;
			}
			total += ft_check_arg(*s, args, flags);
			reset_flags(flags);
		}
		else if (*s != '%')
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
	t_flags	flags;

	total = 0;
	if (!s)
		return (total);
	va_start(args, s);
	reset_flags(&flags);
	total = ft_parse_string(s, args, &flags);
	va_end(args);
	return (total);
}

// int	main(void)
// {
// 	// unsigned int n = 0;
// 	// char *str;
// 	int		res1;
// 	int		res2;

// 	// str = NULL;
// 	// res1 = printf("printf1 == %1s done\n", "");
// 	// res2 = ft_printf("printf2 == %1s done\n", "");
// 	res1 = printf("%1c%2c%3c%4c%1c%2c%3c\n", ' ','!','"','#','$','%','&');
// 	res2 = ft_printf("%1c%2c%3c%4c%1c%2c%3c\n", ' ','!','"','#','$','%','&');
// 	printf("res1 == %d\n", res1);
// 	printf("res2 == %d\n", res2);
// 	return (0);
// }
