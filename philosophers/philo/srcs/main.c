/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/04 15:02:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"
#include "init.h"
#include "monitor.h"
#include "printer.h"
#include "utils.h"

static void	cleanup(t_data *data)
{
	if (ft_usleep(1, data))
		exit_error(SLEEP, data, data->total_philos);
	destroy_mutexes(data, data->total_philos);
	free(data->philos);
	free(data->forks_mtx);
}

static void	simulation(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->total_philos)
	{
		if (!safe_thread(&data->philos[i].thread, &dining,
				&data->philos[i], CREATE))
			exit_error(TH_CREATE, data, data->total_philos);
	}
	if (!safe_thread(&data->monitor, &monitor, data, CREATE))
		exit_error(TH_CREATE, data, data->total_philos);
	if (!safe_thread(&data->monitor, NULL, NULL, JOIN))
		exit_error(TH_JOIN, data, data->total_philos);
	i = -1;
	while (++i < data->total_philos)
		if (!safe_thread(&data->philos[i].thread, NULL, NULL, JOIN))
			exit_error(TH_JOIN, data, data->total_philos);
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
	initialization(&data, &argv[1]);
	simulation(&data);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
