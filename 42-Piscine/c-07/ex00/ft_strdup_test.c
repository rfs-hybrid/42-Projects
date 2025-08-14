/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:34:52 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/08 16:51:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*dup;
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dup = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[src_len] = '\0';
	return (dup);
}

int	main(void)
{
	printf("%s\n", ft_strdup("I am heeeere!!!"));
	printf("%s\n", ft_strdup(""));
}
