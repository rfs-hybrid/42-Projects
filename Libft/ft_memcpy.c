/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:25:49 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/09 17:05:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dstPtr;
	const unsigned char	*srcPtr;

	dstPtr = dest;
	srcPtr = src;
	if (!dstPtr && !srcPtr)
		return (NULL);
	while (n-- > 0)
		dstPtr[n] = srcPtr[n];
	return (dest);
}
