/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:26:01 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/14 13:55:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dst_ptr = dest;
	src_ptr = src;
	if (!dst_ptr && !src_ptr)
		return (NULL);
	if (dst_ptr > src_ptr)
		ft_memcpy(dst_ptr, src_ptr, n);
	else
	{
		i = 0;
		while (i < n)
		{
			*(dst_ptr + i) = *(src_ptr + i);
			i++;
		}
	}
	return (dest);
}
