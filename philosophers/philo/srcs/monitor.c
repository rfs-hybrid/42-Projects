/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:18:03 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 15:49:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "philo.h"
#include "printer.h"
#include "safety.h"
#include "utils.h"

/**
 * @fn static void wait_until_all_philos_ready(t_data *data)
 * @brief Waits until all philosopher threads have initialized and are ready.
 * @details Checks the `philos_ready` counter protected by a mutex.
 * @param data Pointer to the shared data.
 */
static void	wait_until_all_philos_ready(t_data *data)
{
	while (true)
	{
		safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
		if (data->philos_ready == data->total_philos)
		{
			safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
			break ;
		}
		safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
		if (usleep(50) != 0)
			exit_error(SLEEP, data, data->total_philos);
	}
}

/**
 * @fn static void initialize_timer(t_data *data)
 * @brief Sets the start time for the simulation.
 * @details 1. Updates the `last_meal` of all philosophers to the current time
 * to ensure fairness before the simulation officially begins.
 * 2. Sets the global `start_time`, which signals philosopher threads to begin.
 * @param data Pointer to the shared data.
 */
static void	initialize_timer(t_data *data)
{
	int64_t	start_time;
	long	i;

	start_time = ft_gettimeofday_ms();
	i = -1;
	while (++i < data->total_philos)
	{
		safe_mutex(&data->philos[i].meal_mtx, LOCK, data, data->total_philos);
		data->philos[i].last_meal = start_time;
		safe_mutex(&data->philos[i].meal_mtx, UNLOCK, data, data->total_philos);
	}
	safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
	data->start_time = start_time;
	safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
}

/**
 * @fn static void check_meals(t_data *data)
 * @brief Checks if all philosophers have eaten the required number of meals.
 * @details If the optional argument was provided and all philosophers are full,
 * sets the `is_over` flag to true.
 * @param data Pointer to the shared data.
 */
static void	check_meals(t_data *data)
{
	long	full;
	long	i;

	full = 0;
	i = -1;
	while (++i < data->total_philos)
	{
		safe_mutex(&data->philos[i].meal_mtx, LOCK, data, data->total_philos);
		if (data->philos[i].meals_eaten >= data->total_meals)
			full++;
		safe_mutex(&data->philos[i].meal_mtx, UNLOCK, data, data->total_philos);
	}
	if (full == data->total_philos)
	{
		safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
		data->is_over = true;
		safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	}
}

/**
 * @fn static void check_philos(t_data *data)
 * @brief Monitors philosophers for starvation.
 * @details Iterates through all philosophers to check if
 * `current_time - last_meal` exceeds `time_to_die`. If a death is detected, it
 * prints the death message and stops the simulation. Also calls `check_meals`
 * if applicable.
 * @param data Pointer to the shared data.
 */
static void	check_philos(t_data *data)
{
	int64_t	now;
	int64_t	last;
	long	i;

	now = ft_gettimeofday_ms();
	i = -1;
	while (++i < data->total_philos)
	{
		safe_mutex(&data->philos[i].meal_mtx, LOCK, data, data->total_philos);
		last = data->philos[i].last_meal;
		safe_mutex(&data->philos[i].meal_mtx, UNLOCK, data, data->total_philos);
		if (now - last > (int64_t)data->time_to_die)
		{
			safe_print(PHILO_DEAD, &data->philos[i]);
			return ;
		}
	}
	if (data->total_meals != -1)
		check_meals(data);
}

/**
 * @fn void *monitor(void *arg)
 * @brief The routine for the monitor thread.
 * @details 1. Waits for all philosophers to be ready.
 * 2. Initializes the global timer.
 * 3. Loops continuously to check for deaths or full bellies until `is_over` is
 * true.
 * @param arg Void pointer to the data structure.
 * @return NULL.
 */
void	*monitor(void *arg)
{
	t_data	*data;
	bool	is_over;

	data = (t_data *)arg;
	wait_until_all_philos_ready(data);
	initialize_timer(data);
	while (true)
	{
		safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
		is_over = data->is_over;
		safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
		if (is_over)
			break ;
		check_philos(data);
		if (ft_msleep(1, data) != 0)
			exit_error(SLEEP, data, data->total_philos);
	}
	return (NULL);
}
