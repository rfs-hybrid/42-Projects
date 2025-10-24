/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/24 16:35:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "init.h"
#include "printer.h"

static void	check_args(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		print_message(NUM_ARGS, NULL);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[++i])
	{
		if (ft_atol(argv[i]) <= 0)
		{
			print_message(POS_ARGS, NULL);
			exit(EXIT_FAILURE);
		}
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	philo_init(&data, &argv[1]);
	return (EXIT_SUCCESS);
}
