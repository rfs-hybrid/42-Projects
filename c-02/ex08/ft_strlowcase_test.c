/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:09:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/26 12:27:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	buf1[] = "HELLOWORLD";
	char	buf2[] = "H3110W0R1D";
	char	buf3[] = "i AM hErE!!!";

	printf("%s\n", ft_strlowcase(buf1));
	printf("%s\n", ft_strlowcase(buf2));
	printf("%s\n", ft_strlowcase(buf3));
}
