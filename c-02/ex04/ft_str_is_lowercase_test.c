/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase_test.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:02:21 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/25 13:45:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char	buf1[] = "abcdefghijklmnopqrstuvwxyz";
	char	buf2[] = "AbCdEfGhIjKlMnOpQrStUvWxYz";
	char	buf3[] = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
	char	buf4[] = "";

	printf("%d\n", ft_str_is_lowercase(buf1));
	printf("%d\n", ft_str_is_lowercase(buf2));
	printf("%d\n", ft_str_is_lowercase(buf3));
	printf("%d\n", ft_str_is_lowercase(buf4));
}
