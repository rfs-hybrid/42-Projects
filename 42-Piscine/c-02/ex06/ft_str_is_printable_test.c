/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:47:39 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/26 12:57:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (*str < 32 || *str == 127)
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char buf1[] = {'I', ' ', 'a', 'm', ' ', 'h', 'e', 'r', 'e', '!'};
	char buf2[] = {'H', 'e', 'l', 'l', 'o', '~'};
	char buf3[] = {31, 'Y', 'o'};
	char buf4[] = {'N', 'o', 'p', 'e', 127};
	char buf5[] = "";

	printf("%d\n", ft_str_is_printable(buf1));
	printf("%d\n", ft_str_is_printable(buf2));
	printf("%d\n", ft_str_is_printable(buf3));
	printf("%d\n", ft_str_is_printable(buf4));
	printf("%d\n", ft_str_is_printable(buf5));
}
