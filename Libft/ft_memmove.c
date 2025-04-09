/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:26:01 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/09 17:26:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dstPtr;
	const unsigned char	*srcPtr;
    size_t              i;

	dstPtr = dest;
	srcPtr = src;
	if (!dstPtr && !srcPtr)
		return (NULL);
    if (dstPtr > srcPtr)
    {
	    while (n-- > 0)
		    dstPtr[n] = srcPtr[n];
    }
    else
    {
        i = 0;
        while (i < n)
        {
            dstPtr[i] = srcPtr[i];
            i++;
        }    
    }
	return (dest);
}
