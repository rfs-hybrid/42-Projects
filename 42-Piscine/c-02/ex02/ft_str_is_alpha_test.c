/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:48:03 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/01 15:48:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (!str)
		return (1);
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char buff1[] = "HelloWorld";
	char buff2[] = "H3ll0W0rld";
	char buff3[] = "Hello\tWorld\n";
	char buff4[] = "";
	printf("%d\n", ft_str_is_alpha(buff1));
	printf("%d\n", ft_str_is_alpha(buff2));
	printf("%d\n", ft_str_is_alpha(buff3));
	printf("%d\n", ft_str_is_alpha(buff4));
}
