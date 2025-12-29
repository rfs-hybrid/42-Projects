/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:19:54 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_bonus.h"
#include "monitor_bonus.h"
#include "philo_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void philo_routine(t_philo *philo, t_data *data)
 * @brief Executes one cycle of eating, sleeping, and thinking.
 * @details 1. Acquires `waiter` semaphore to prevent deadlock (limits
 * concurrent eaters).
 * 2. Acquires two forks from the global pool.
 * 3. Eats (updates `last_meal`, signals `full` if quota reached).
 * 4. Sleeps.
 * 5. Thinks.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 */
static void	philo_routine(t_philo *philo, t_data *data)
{
	safe_sem(data->waiter, WAIT, data);
	safe_sem(data->forks, WAIT, data);
	safe_print(PHILO_FORK, philo);
	safe_sem(data->forks, WAIT, data);
	safe_print(PHILO_FORK, philo);
	safe_sem(data->meal, WAIT, data);
	philo->last_meal = ft_gettimeofday_ms();
	philo->meals_eaten++;
	if (data->total_meals != -1 && philo->meals_eaten >= data->total_meals)
	{
		safe_sem(data->full, POST, data);
		data->total_meals = -1;
	}
	safe_sem(data->meal, POST, data);
	safe_print(PHILO_EAT, philo);
	if (ft_msleep(data->time_to_eat) != 0)
		exit_error(SLEEP, data);
	safe_sem(data->forks, POST, data);
	safe_sem(data->forks, POST, data);
	safe_sem(data->waiter, POST, data);
	safe_print(PHILO_SLEEP, philo);
	if (ft_msleep(data->time_to_sleep) != 0)
		exit_error(SLEEP, data);
	safe_print(PHILO_THINK, philo);
}

/**
 * @fn void dining(t_philo *philo)
 * @brief The main routine for a philosopher child process.
 * @details 1. Initializes local start times.
 * 2. Starts the monitoring thread for this specific process.
 * 3. Handles the single philosopher edge case.
 * 4. Staggers even-numbered philosophers to reduce initial contention.
 * 5. Enters the infinite `philo_routine` loop.
 * @param philo Pointer to the philosopher structure.
 */
void	dining(t_philo *philo)
{
	philo->pid = 0;
	philo->data->start_time = ft_gettimeofday_ms();
	philo->last_meal = philo->data->start_time;
	if (!safe_thread(&philo->monitor, &monitor_philo_status, philo, CREATE))
		exit_error(TH_CREATE, philo->data);
	if (philo->data->total_philos == 1)
	{
		safe_sem(philo->data->forks, WAIT, philo->data);
		safe_print(PHILO_FORK, philo);
		safe_sem(philo->data->forks, WAIT, philo->data);
	}
	if (philo->philo_id % 2 == 0 && usleep(10000))
		exit_error(SLEEP, philo->data);
	while (true)
		philo_routine(philo, philo->data);
}
