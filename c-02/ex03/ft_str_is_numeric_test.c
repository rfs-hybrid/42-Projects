/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:02:29 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/25 13:46:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char buf1[] = "HelloWorld";
	char buf2[] = "53110";
	char buf3[] = "04 01";
	char buf4[] = "";

	printf("%d\n", ft_str_is_numeric(buf1));
	printf("%d\n", ft_str_is_numeric(buf2));
	printf("%d\n", ft_str_is_numeric(buf3));
	printf("%d\n", ft_str_is_numeric(buf4));
}
