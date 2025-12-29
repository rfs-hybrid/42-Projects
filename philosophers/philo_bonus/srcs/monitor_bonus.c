/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:18:03 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:17:28 by maaugust         ###   ########.fr       */
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
 * @details Runs inside each child process. It continuously checks if the
 * philosopher has starved. If death is detected, it prints the death message,
 * posts the global `stop` semaphore (signaling the parent), and exits the
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
 * @fn void *monitor_philo_meals(void *arg)
 * @brief Thread routine that monitors global meal completion.
 * @details Runs as a detached thread in the parent process. It waits for
 * `total_philos` posts on the `full` semaphore. Once all philosophers are
 * full, it posts the global `stop` semaphore to end the simulation.
 * @param arg Void pointer to the main data structure.
 * @return NULL.
 */
void	*monitor_philo_meals(void *arg)
{
	t_data	*data;
	long	i;

	data = (t_data *)arg;
	i = -1;
	while (++i < data->total_philos)
		safe_sem(data->full, WAIT, data);
	safe_sem(data->stop, POST, data);
	return (NULL);
}
