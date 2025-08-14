/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:41:56 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/02 17:45:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	return (0);
}
