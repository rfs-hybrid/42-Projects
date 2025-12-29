/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:20 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:42:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"
#include "printer.h"
#include "safety.h"
#include "utils.h"

/**
 * @fn static void mutexes_init(t_data *data)
 * @brief Initializes all mutexes used in the simulation.
 * @details Initializes global mutexes (print, status, ready) and individual
 * mutexes for forks and philosopher meal data.
 * @param data Pointer to the main data structure.
 */
static void	mutexes_init(t_data *data)
{
	long	i;

	safe_mutex(&data->print_mtx, INIT, data, 0);
	safe_mutex(&data->status_mtx, INIT, data, 0);
	safe_mutex(&data->ready_mtx, INIT, data, 0);
	i = -1;
	while (++i < data->total_philos)
	{
		if (pthread_mutex_init(&data->forks_mtx[i], NULL) != 0)
			exit_error(MTX_INIT, data, i);
		if (pthread_mutex_init(&data->philos[i].meal_mtx, NULL) != 0)
		{
			pthread_mutex_destroy(&data->forks_mtx[i]);
			exit_error(MTX_INIT, data, i);
		}
	}
}

/**
 * @fn static void	philo_data(t_data *data, t_philo *philo, long index,
 * long total)
 * @brief Sets initial values for a single philosopher.
 * @details Assigns ID, meal counters, and determines the left/right fork
 * indices.
 * @param data Pointer to the shared data structure.
 * @param philo Pointer to the specific philosopher structure to initialize.
 * @param index The index of the philosopher (0 to total-1).
 * @param total Total number of philosophers (used for fork logic).
 */
static void	philo_data(t_data *data, t_philo *philo, long index, long total)
{
	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = index + 1;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->fork_a = index;
	philo->fork_b = (index + 1) % total;
	philo->data = data;
}

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Parses arguments and initializes the main data structure.
 * @details Converts arguments to integers, allocates memory for philosophers and
 * mutexes, and calls sub-initialization functions. Handles memory allocation
 * errors.
 * @param data Pointer to the main data structure.
 * @param argv Argument vector (shifted by 1 to skip program name).
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
	data->philos_ready = 0;
	data->start_time = 0;
	data->is_over = false;
	data->philos = safe_malloc(sizeof(t_philo) * data->total_philos);
	data->forks_mtx = safe_malloc(sizeof(t_mtx) * data->total_philos);
	if (!data->philos || !data->forks_mtx)
		exit_error(MALLOC, data, 0);
	i = -1;
	while (++i < data->total_philos)
		philo_data(data, &data->philos[i], i, data->total_philos);
	mutexes_init(data);
}
