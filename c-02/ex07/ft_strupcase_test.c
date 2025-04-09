/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:09:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/26 12:21:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	buf1[] = "helloworld";
	char	buf2[] = "h3110w0r1d";
	char	buf3[] = "I am here!!!";

	printf("%s\n", ft_strupcase(buf1));
	printf("%s\n", ft_strupcase(buf2));
	printf("%s\n", ft_strupcase(buf3));
}
