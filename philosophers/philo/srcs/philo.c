/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/31 17:27:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dining.h"
#include "init.h"
#include "monitor.h"
#include "printer.h"
#include "safety.h"
#include "utils.h"

/**
 * @fn bool handle_single_philo(t_philo *philo, t_data *data)
 * @brief Handles the specific edge case of a single philosopher.
 * @details A single philosopher takes one fork, waits for `time_to_die`, and
 * then dies. This function handles the locking, printing, and sleeping for
 * that scenario.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 * @return Always returns false to stop the routine.
 */
bool	handle_single_philo(t_philo *philo, t_data *data)
{
	safe_mutex(&data->forks_mtx[philo->fork_a], LOCK, data, data->total_philos);
	safe_print(PHILO_FORK, philo);
	if (ft_msleep(data->time_to_die, data) != 0)
		exit_error(SLEEP, data, data->total_philos);
	safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
		data->total_philos);
	return (false);
}

/**
 * @fn static void cleanup(t_data *data)
 * @brief Cleans up resources before the program exits.
 * @details Waits for a brief moment to ensure threads have settled, then
 * destroys all mutexes and frees allocated memory for philosophers and fork
 * locks.
 * @param data Pointer to the main data structure containing all resources.
 */
static void	cleanup(t_data *data)
{
	if (ft_msleep(1, data) != 0)
		exit_error(SLEEP, data, data->total_philos);
	destroy_mutexes(data, data->total_philos);
	free(data->philos);
	free(data->forks_mtx);
}

/**
 * @fn static void simulation(t_data *data)
 * @brief Launches the simulation threads.
 * @details Creates a thread for each philosopher to run the `dining` routine.
 * Then creates the monitor thread. Finally, it joins the monitor thread
 * (waiting for it to finish) and then joins all philosopher threads.
 * @param data Pointer to the main data structure.
 */
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

/**
 * @fn static void check_args(int argc, char **argv)
 * @brief Validates command-line arguments.
 * @details Checks if the argument count is 5 or 6 and ensures all arguments
 * are positive integers. If validation fails, it prints an error message
 * and exits.
 * @param argc Argument count.
 * @param argv Argument vector.
 */
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

/**
 * @fn int main(int argc, char **argv)
 * @brief Main entry point of the Philosophers program.
 * @details Orchestrates the flow: validates arguments, initializes
 * data/mutexes, runs the simulation, and performs cleanup upon completion.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	initialization(&data, &argv[1]);
	simulation(&data);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
