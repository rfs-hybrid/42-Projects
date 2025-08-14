/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:11:54 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/01 20:38:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_ptr;
	char	*to_find_ptr;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		str_ptr = str;
		to_find_ptr = to_find;
		while (*str_ptr && *to_find_ptr && *str_ptr == *to_find_ptr)
		{
			str_ptr++;
			to_find_ptr++;
		}
		if (!(*to_find_ptr))
			return (str);
		str++;
	}
	return (0);
}

int	main(void)
{
	printf ("%s\n", ft_strstr("Hello World!", "lo "));
}
