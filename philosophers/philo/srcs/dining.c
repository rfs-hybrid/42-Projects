/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 15:46:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"
#include "monitor.h"
#include "utils.h"

/**
 * @fn static bool handle_single_philo(t_philo *philo, t_data *data)
 * @brief Handles the specific edge case of a single philosopher.
 * @details A single philosopher takes one fork, waits for `time_to_die`, and
 * then dies. This function handles the locking, printing, and sleeping for
 * that scenario.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 * @return Always returns false to stop the routine.
 */
static bool	handle_single_philo(t_philo *philo, t_data *data)
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
 * @fn static void release_forks(t_philo *philo, t_data *data)
 * @brief Unlocks both forks held by a philosopher.
 * @details Only attempts to unlock if there is more than one philosopher.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 */
static void	release_forks(t_philo *philo, t_data *data)
{
	if (data->total_philos > 1)
	{
		safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
			data->total_philos);
		safe_mutex(&data->forks_mtx[philo->fork_b], UNLOCK, data,
			data->total_philos);
	}
}

/**
 * @fn static bool pick_forks(t_philo *philo, t_data *data)
 * @brief Attempts to lock two forks for the philosopher.
 * @details Implements a resource hierarchy solution to prevent deadlocks:
 * - Odd philosophers lock fork B then A.
 * - Even philosophers lock fork A then B.
 * Also checks if the simulation is over after locking.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 * @return true if forks were successfully picked and simulation is running,
 * false otherwise.
 */
static bool	pick_forks(t_philo *philo, t_data *data)
{
	long	fork_a;
	long	fork_b;
	bool	is_over;

	if (data->total_philos == 1)
		return (handle_single_philo(philo, data));
	fork_a = philo->fork_a;
	fork_b = philo->fork_b;
	if (philo->philo_id % 2 == 1)
	{
		safe_mutex(&data->forks_mtx[fork_b], LOCK, data, data->total_philos);
		safe_print(PHILO_FORK, philo);
		safe_mutex(&data->forks_mtx[fork_a], LOCK, data, data->total_philos);
	}
	else
	{
		safe_mutex(&data->forks_mtx[fork_a], LOCK, data, data->total_philos);
		safe_print(PHILO_FORK, philo);
		safe_mutex(&data->forks_mtx[fork_b], LOCK, data, data->total_philos);
	}
	safe_print(PHILO_FORK, philo);
	safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
	is_over = data->is_over;
	safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	return (!is_over);
}

/**
 * @fn static bool philo_routine(t_philo *philo, t_data *data)
 * @brief Executes one cycle of eating, sleeping, and thinking.
 * @details 1. Checks if simulation is over.
 * 2. Picks forks.
 * 3. Updates last_meal time and meals_eaten count (protected).
 * 4. Eats (sleeps for time_to_eat).
 * 5. Releases forks.
 * 6. Sleeps (for time_to_sleep).
 * 7. Thinks.
 * @param philo Pointer to the philosopher.
 * @param data Pointer to the shared data.
 * @return true to continue to the next cycle, false to stop.
 */
static bool	philo_routine(t_philo *philo, t_data *data)
{
	bool	is_over;

	safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
	is_over = data->is_over;
	safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	if (is_over)
		return (false);
	if (!pick_forks(philo, data))
	{
		release_forks(philo, data);
		return (false);
	}
	safe_mutex(&philo->meal_mtx, LOCK, data, data->total_philos);
	philo->last_meal = ft_gettimeofday_ms();
	philo->meals_eaten += 1;
	safe_mutex(&philo->meal_mtx, UNLOCK, data, data->total_philos);
	safe_print(PHILO_EAT, philo);
	if (ft_msleep(data->time_to_eat, data) != 0)
		exit_error(SLEEP, data, data->total_philos);
	release_forks(philo, data);
	safe_print(PHILO_SLEEP, philo);
	if (ft_msleep(data->time_to_sleep, data) != 0)
		exit_error(SLEEP, data, data->total_philos);
	safe_print(PHILO_THINK, philo);
	return (true);
}

/**
 * @fn void *dining(void *arg)
 * @brief The main thread routine for a philosopher.
 * @details 1. Signals readiness to the monitor.
 * 2. Spins/waits until the global `start_time` is set.
 * 3. Even-numbered philosophers delay slightly to prevent start contention.
 * 4. Loops through `philo_routine` until the simulation ends.
 * @param arg Void pointer to the philosopher structure.
 * @return NULL.
 */
void	*dining(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
	data->philos_ready++;
	safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
	while (true)
	{
		safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
		if (data->start_time != 0)
		{
			safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
			break ;
		}
		safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
		if (usleep(50) != 0)
			exit_error(SLEEP, data, data->total_philos);
	}
	if (philo->philo_id % 2 == 0)
		ft_msleep(1, data);
	while (philo_routine(philo, data))
		;
	return (NULL);
}
