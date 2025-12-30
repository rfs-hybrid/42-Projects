/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:18:03 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/30 15:27:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor_bonus.h"
#include "philo_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn void *monitor_philo_status(void *arg)
 * @brief Thread routine that monitors the death status of a single philosopher.
 * @details Runs as a thread inside each philosopher's child process. It
 * continuously checks if the philosopher has starved. If death is detected,
 * it prints the message, signals the global `stop` semaphore, and exits the
 * process.
 * @param arg Void pointer to the philosopher structure.
 * @return NULL.
 */
void	*monitor_philo_status(void *arg)
{
	t_philo	*philo;
	int64_t	now;
	int64_t	last;

	philo = (t_philo *)arg;
	while (true)
	{
		now = ft_gettimeofday_ms();
		safe_sem(philo->data->meal, WAIT, philo->data);
		last = philo->last_meal;
		safe_sem(philo->data->meal, POST, philo->data);
		if (now - last > (int64_t)philo->data->time_to_die)
		{
			safe_print(PHILO_DEAD, philo);
			safe_sem(philo->data->stop, POST, philo->data);
			exit(EXIT_FAILURE);
		}
		if (ft_msleep(1) != 0)
			exit_error(SLEEP, philo->data);
	}
	return (NULL);
}

/**
 * @fn void monitor_philo_meals(t_data *data)
 * @brief Routine for the dedicated meal monitoring process.
 * @details Runs in a separate child process. Waits for `total_philos` signals
 * on the `full` semaphore. Once all philosophers have eaten enough, it posts
 * the `stop` semaphore to end the simulation and exits successfully.
 * @param data Pointer to the main data structure.
 */
void	monitor_philo_meals(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->total_philos)
		safe_sem(data->full, WAIT, data);
	safe_sem(data->stop, POST, data);
	exit(EXIT_SUCCESS);
}
