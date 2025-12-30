/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:04:33 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/30 15:25:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "init_bonus.h"
#include "monitor_bonus.h"
#include "printer_bonus.h"
#include "simulation_bonus.h"
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
 * data/semaphores, hands control to the simulation module, and performs
 * cleanup.
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
