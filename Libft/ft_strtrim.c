/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:35 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/10 15:50:55 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!(*set))
		return ((char *)s1);
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && isset(s1[start], set) && start < len)
		start++;
	end = 0;
	if (start != len)
	{
		while (s1[len - end - 1] && isset(s1[len - end - 1], set) && end < len)
			end++;
	}
	trim = (char *)ft_calloc(len - start - end + 1, sizeof(char));
	if (!trim)
		return (NULL);
	ft_memmove(trim, s1 + start, len - start - end);
	return (trim);
}
