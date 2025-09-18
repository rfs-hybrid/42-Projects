/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/17 23:33:56 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"
#include "printer.h"

static bool	args_valid(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		print_message(NUM_ARGS, NULL);
		return (false);
	}
	i = 0;
	while (argv[++i])
		if (!ft_atoul(argv[i]))
			return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	// t_data	data;

	if (!args_valid(argc, argv))
		return (EXIT_FAILURE);
	// philo_init(&data, &argv[1]);
	return (EXIT_SUCCESS);
}
