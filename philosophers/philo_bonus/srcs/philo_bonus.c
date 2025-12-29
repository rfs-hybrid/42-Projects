/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 16:38:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "dining_bonus.h"
#include "init_bonus.h"
#include "monitor_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void cleanup(t_data *data)
 * @brief Cleans up resources before the program exits.
 * @details Unlinks and closes all semaphores and frees the allocated memory
 * for the philosopher structures.
 * @param data Pointer to the main data structure containing all resources.
 */
static void	cleanup(t_data *data)
{
	destroy_semaphores(data);
	free(data->philos);
}

/**
 * @fn static void start_processes(t_data *data)
 * @brief Creates child processes for the simulation.
 * @details Loops through the total number of philosophers and forks a new
 * process for each. Each child process runs the `dining` routine.
 * If a fork fails, it kills all previously created processes and exits.
 * @param data Pointer to the main data structure.
 */
static void	start_processes(t_data *data)
{
	pid_t	pid;
	long	i;

	i = -1;
	while (++i < data->total_philos)
	{
		pid = fork();
		if (pid == -1)
		{
			while (--i >= 0)
				kill(data->philos[i].pid, SIGKILL);
			exit_error(FORK, data);
		}
		if (pid == 0)
			dining(&data->philos[i]);
		data->philos[i].pid = pid;
	}
}

/**
 * @fn static void simulation(t_data *data)
 * @brief Orchestrates the main simulation flow in the parent process.
 * @details 1. Starts all child processes.
 * 2. If a meal limit is set, creates a detached thread to monitor meal counts.
 * 3. Waits on the `stop` semaphore (blocks until a philosopher dies or everyone
 * is full).
 * 4. Kills all child processes immediately upon waking up.
 * 5. Waits for all child processes to prevent zombie processes.
 * @param data Pointer to the main data structure.
 */
static void	simulation(t_data *data)
{
	pthread_t	meal;
	long		i;

	start_processes(data);
	if (data->total_meals != -1)
	{
		if (!safe_thread(&meal, &monitor_philo_meals, data, CREATE))
			exit_error(TH_CREATE, data);
		safe_thread(&meal, NULL, NULL, DETACH);
	}
	safe_sem(data->stop, WAIT, data);
	i = -1;
	while (++i < data->total_philos)
		kill(data->philos[i].pid, SIGKILL);
	i = -1;
	while (++i < data->total_philos)
		waitpid(data->philos[i].pid, NULL, 0);
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
 * @brief Main entry point of the Philosophers Bonus program.
 * @details Orchestrates the flow: validates arguments, initializes
 * data/semaphores, runs the process-based simulation, and performs cleanup
 * upon completion.
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
