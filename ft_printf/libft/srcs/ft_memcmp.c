/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/10 12:14:00 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = s1;
	s2_ptr = s2;
	i = 0;
	while (i < n && *(s1_ptr + i) == *(s2_ptr + i))
		i++;
	if (i == n)
		return (0);
	return ((*(s1_ptr + i)) - (*(s2_ptr + i)));
}
