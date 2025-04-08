/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:33:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/27 12:38:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	printf ("%d\n", ft_strcmp("ABC", "ABC"));
	printf ("%d\n", ft_strcmp("ABC", "AB"));
	printf ("%d\n", ft_strcmp("ABA", "ABZ"));
	printf ("%d\n", ft_strcmp("ABJ", "ABC"));
}
