/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:20 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:15:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_bonus.h"
#include "philo_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void semaphore_init(t_data *data)
 * @brief Initializes all named semaphores used in the simulation.
 * @details Unlinks any existing semaphores with the same names first, then
 * opens new ones.
 * - `stop`: Main stop signal (0).
 * - `print`: Serializes output (1).
 * - `meal`: Protects meal data access (1).
 * - `full`: Counts full philosophers (0).
 * - `waiter`: Limits concurrent eaters (total_philos - 1).
 * - `forks`: The pool of forks (total_philos).
 * @param data Pointer to the main data structure.
 */
static void	semaphore_init(t_data *data)
{
	sem_unlink(SEM_STOP);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_MEAL);
	sem_unlink(SEM_FULL);
	sem_unlink(SEM_WAITER);
	sem_unlink(SEM_FORKS);
	data->stop = sem_open(SEM_STOP, O_CREAT, 0644, 0);
	data->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	data->meal = sem_open(SEM_MEAL, O_CREAT, 0644, 1);
	data->full = sem_open(SEM_FULL, O_CREAT, 0644, 0);
	data->waiter = sem_open(SEM_WAITER, O_CREAT, 0644, data->total_philos - 1);
	data->forks = sem_open(SEM_FORKS, O_CREAT, 0644, data->total_philos);
	if (data->stop == SEM_FAILED || data->print == SEM_FAILED
		|| data->meal == SEM_FAILED || data->full == SEM_FAILED
		|| data->waiter == SEM_FAILED || data->forks == SEM_FAILED)
		exit_error(SEM_OPEN, data);
}

/**
 * @fn static void philo_data(t_data *data, t_philo *philo, long index)
 * @brief Sets initial values for a single philosopher.
 * @details Assigns ID and resets meal counters.
 * @param data Pointer to the shared data structure.
 * @param philo Pointer to the specific philosopher structure to initialize.
 * @param index The index of the philosopher (0 to total-1).
 */
static void	philo_data(t_data *data, t_philo *philo, long index)
{
	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = index + 1;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->data = data;
}

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Parses arguments and initializes the main data structure.
 * @details Converts arguments to integers, allocates memory for philosophers,
 * and calls sub-initialization functions for data and semaphores.
 * @param data Pointer to the main data structure to initialize.
 * @param argv Command line arguments (shifted to start at the first parameter).
 */
void	initialization(t_data *data, char **argv)
{
	long	i;

	data->total_philos = ft_atol(*argv++);
	data->time_to_die = ft_atol(*argv++);
	data->time_to_eat = ft_atol(*argv++);
	data->time_to_sleep = ft_atol(*argv++);
	data->total_meals = -1;
	if (*argv)
		data->total_meals = ft_atol(*argv);
	data->start_time = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
		exit_error(MALLOC, data);
	i = -1;
	while (++i < data->total_philos)
		philo_data(data, &data->philos[i], i);
	semaphore_init(data);
}
