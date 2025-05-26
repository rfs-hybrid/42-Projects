/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:39:26 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/26 15:59:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (src_len);
}

char	*ft_str_realloc(char **str, size_t size)
{
	char	*new;
	size_t	len;

	if (!str || !*str)
	{
		new = (char *) malloc(sizeof(char) * (size + 1));
		if (!new)
			return (free(*str), NULL);
		*new = '\0';
	}
	else
	{
		len = ft_strlen(*str);
		new = (char *) malloc(sizeof(char) * (len + size + 1));
		if (!new)
			return (free(*str), NULL);
		ft_strlcpy(new, *str, len + 1);
		free(*str);
		str = NULL;
	}
	return (new);
}
