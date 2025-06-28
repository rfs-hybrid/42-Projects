/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:04:16 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/10 11:44:16 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(s2 + i) && *(s1 + i) == *(s2 + i))
		i++;
	if (i == n)
		return (0);
	return ((*((unsigned char *)(s1 + i))) - (*((unsigned char *)(s2 + i))));
}
