/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:42 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/10 12:26:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*little) || big == little)
		return ((char *)big);
	i = 0;
	while (*(big + i) && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j])
			j++;
		if (!(i + j < len))
			break ;
		if (!(*(little + j)))
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
