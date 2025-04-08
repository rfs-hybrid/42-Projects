/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:11:41 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/01 22:17:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_get_hex_char(unsigned char val)
{
	char	*hex_char;

	hex_char = "0123456789abcdef";
	return (hex_char[val]);
}

void	ft_write_in_hex(unsigned char c)
{
	char	digit1;
	char	digit0;

	digit1 = ft_get_hex_char(c / 16);
	digit0 = ft_get_hex_char(c % 16);
	write (1, &digit1, 1);
	write (1, &digit0, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < ' ' || *str > '~')
		{
			write (1, "\\", 1);
			ft_write_in_hex(*str);
		}
		else
			write (1, str, 1);
		str++;
	}
}

int	main(void)
{
	char buf[50] = {'O','l','a','\r','e','s','t','a',' ','b','e','m','?','\n',127};
	ft_putstr_non_printable(buf);
//	ft_putstr_non_printable("Ola\resta bem?\n");
}
