/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:32:39 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/11 16:10:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_memory(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
		str = (char *)ft_calloc(1, sizeof(char));
	else if (ft_strlen(s) - start < len)
		str = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = allocate_memory(s, start, len);
	if (!sub)
		return (NULL);
	if (start < ft_strlen(s))
	{
		i = 0;
		while (*(s + (start + i)) && i < len)
		{
			*(sub + i) = *(s + (start + i));
			i++;
		}
	}
	return (sub);
}
