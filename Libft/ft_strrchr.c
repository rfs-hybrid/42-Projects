/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:06 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/11 15:41:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	ptr = NULL;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (*(s + i) == (char)c)
			ptr = (char *)(s + i);
		i++;
	}
	return (ptr);
}
