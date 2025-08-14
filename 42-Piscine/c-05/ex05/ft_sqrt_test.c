/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:24:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 19:45:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;

	if (nb < 0)
		return (0);
	root = 0;
	while (root * root <= nb && !(root * root < 0))
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int	num = 1000001;
	printf ("%d\n", ft_sqrt(num));
}
