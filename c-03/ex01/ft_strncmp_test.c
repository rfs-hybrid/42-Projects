/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:23:48 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/06 15:36:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

int	main(void)
{
	int n = 3;
	printf ("%d\n", ft_strncmp("ABC", "ABC", n));
	printf ("%d\n", ft_strncmp("ABC", "ABC", 5));
	printf ("%d\n", ft_strncmp("ABC", "AB", n));
	printf ("%d\n", ft_strncmp("ABC", "AB", 2));
	printf ("%d\n", ft_strncmp("ABA", "ABZ", n));
	printf ("%d\n", ft_strncmp("ABJ", "ABC", 2));
}
