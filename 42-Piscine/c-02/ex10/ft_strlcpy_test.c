/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:41:44 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/01 17:21:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (src_len);
}

int	main(void)
{
	char str1[20];
	char str2[] = "Hello there, Venus!";
	unsigned int	ret_val;
	ret_val = ft_strlcpy(str1, str2, 0);
	printf ("%s\n", str1);
	printf ("strlcpy output: %u\n", ret_val);
}
