/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:09:05 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/09 19:02:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	if (size > 0)
	{
		while (i + dst_len < size - 1 && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
