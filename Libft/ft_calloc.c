/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:32:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/10 14:13:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;

	arr = (unsigned char *)malloc(sizeof(unsigned char) * (nmemb * size));
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
