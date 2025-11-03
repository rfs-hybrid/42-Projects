/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/03 22:23:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "printer.h"
#include "simulation.h"
#include "utils.h"

static void	cleanup(t_data *data)
{
	if (ft_usleep(1, data))
		exit_error(SLEEP, data, data->total_philos);
	destroy_mutexes(data, data->total_philos);
	free(data->philos);
	free(data->forks_mtx);
}

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
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	philo_init(&data, &argv[1]);
	philo_sim(&data);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
