/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:57:14 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/03 18:28:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				ft_putchar(argv[i][j]);
			ft_putchar('\n');
		}
	}
	return (0);
}
