/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:41:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/02 09:57:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	if (size < dest_len)
		return (src_len + size);
	return (src_len + dest_len);
}

int	main(void)
{
	char str1[] = "Hello ";
	char str2[] = "World!";
	unsigned int	length;
	printf ("Before -> %s\n", str1);
	length = ft_strlcat(str1, str2, 10);
	printf ("After -> %s\n", str1);
	printf ("strlcat output: %d\n", length);
	return (0);
}
