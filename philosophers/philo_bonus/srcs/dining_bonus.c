/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/02 21:18:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining_bonus.h"
#include "monitor_bonus.h"
#include "philo_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void release_forks(t_data *data)
 * @brief Releases acquired resources after eating.
 * @details Posts to the forks semaphore twice and the waiter semaphore once,
 * allowing other philosophers to enter the eating queue.
 * @param data Pointer to shared data.
 */
static void	release_forks(t_data *data)
{
	safe_sem(data->forks, POST, data);
	safe_sem(data->forks, POST, data);
	safe_sem(data->waiter, POST, data);
}

/**
 * @fn static void pick_forks(t_philo *philo, t_data *data)
 * @brief Acquires resources necessary for eating.
 * @details 
 * 1. Waits on `waiter` semaphore (limits table access to N-1).
 * 2. Waits on `forks` semaphore twice.
 * 3. Prints fork acquisition messages.
 * @param philo Pointer to philosopher.
 * @param data Pointer to shared data.
 */
static void	pick_forks(t_philo *philo, t_data *data)
{
	safe_sem(data->waiter, WAIT, data);
	safe_sem(data->forks, WAIT, data);
	safe_print(PHILO_FORK, philo);
	safe_sem(data->forks, WAIT, data);
	safe_print(PHILO_FORK, philo);
}

/**
 * @fn static void eating_sleeping(t_philo *philo, t_data *data)
 * @brief Handles the eating and sleeping phases.
 * @details 
 * 1. Locks `meal` semaphore to update `last_meal`.
 * 2. performs a strict death check: if the philosopher died while waiting
 * for forks, it releases resources and exits immediately.
 * 3. Updates meal counters and posts `full` if applicable.
 * 4. Prints status, sleeps for `time_to_eat`, releases forks, then sleeps.
 * @param philo Pointer to philosopher.
 * @param data Pointer to shared data.
 */
static void	eating_sleeping(t_philo *philo, t_data *data)
{
	safe_sem(philo->meal, WAIT, data);
	if (ft_gettimeofday_ms() - philo->last_meal >= data->time_to_die)
	{
		safe_sem(philo->meal, POST, data);
		release_forks(data);
		safe_print(PHILO_DEAD, philo);
		safe_sem(data->stop, POST, data);
		exit(EXIT_FAILURE);
	}
	philo->last_meal = ft_gettimeofday_ms();
	philo->meals_eaten++;
	if (data->total_meals != -1 && philo->meals_eaten >= data->total_meals)
	{
		safe_sem(data->full, POST, data);
		data->total_meals = -1;
	}
	safe_sem(philo->meal, POST, data);
	safe_print(PHILO_EAT, philo);
	if (ft_msleep(data->time_to_eat) != 0)
		exit_error(SLEEP, data);
	release_forks(data);
	safe_print(PHILO_SLEEP, philo);
	if (ft_msleep(data->time_to_sleep) != 0)
		exit_error(SLEEP, data);
}

/**
 * @fn static void philo_routine(t_philo *philo, t_data *data)
 * @brief Executes one cycle of eating, sleeping, and thinking.
 * @details
 * 1. Acquires `waiter` semaphore to prevent deadlock (limits
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
	long	time_to_think;

	pick_forks(philo, data);
	eating_sleeping(philo, data);
	safe_print(PHILO_THINK, philo);
	if (data->total_philos % 2 != 0)
	{
		time_to_think = (data->time_to_eat * 2) - data->time_to_sleep;
		if (time_to_think < 0)
			time_to_think = 0;
		if (time_to_think > 0 && ft_msleep(time_to_think) != 0)
			exit_error(SLEEP, data);
		if (usleep(500) != 0)
			exit_error(SLEEP, data);
	}
}

/**
 * @fn void dining(t_philo *philo)
 * @brief The main routine for a philosopher child process.
 * @details
 * 1. Initializes local start times.
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
	if (philo->philo_id % 2 == 0 && ft_msleep(40) != 0)
		exit_error(SLEEP, philo->data);
	while (true)
		philo_routine(philo, philo->data);
}
