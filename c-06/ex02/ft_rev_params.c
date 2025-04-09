/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:32:53 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 20:41:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	while (argc > 1)
	{
		while (*argv[argc - 1])
		{
			write (1, argv[argc - 1], 1);
			argv[argc - 1]++;
		}
		write (1, "\n", 1);
		argc--;
	}
	return (0);
}
