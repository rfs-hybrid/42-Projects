/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:13:10 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 19:22:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (src[++i])
		dup[i] = src[i];
	dup[i] = '\0';
	return (dup);
}
