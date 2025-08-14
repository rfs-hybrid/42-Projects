/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:46:12 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 17:49:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("length == %d\n", ft_strlen(argv[1]));
	return (0);
}
