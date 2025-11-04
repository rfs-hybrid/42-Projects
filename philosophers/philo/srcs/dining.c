/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/04 15:04:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dining.h"
#include "monitor.h"
#include "utils.h"

static bool	handle_single_philo(t_philo *philo, t_data *data)
{
	safe_mutex(&data->forks_mtx[philo->fork_a], LOCK, data, data->total_philos);
	safe_print(PHILO_FORK, philo);
	if (ft_usleep(data->time_to_die, data))
		exit_error(SLEEP, data, data->total_philos);
	safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
		data->total_philos);
	return (false);
}

static void	release_forks(t_philo *philo, t_data *data)
{
	safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
		data->total_philos);
	safe_mutex(&data->forks_mtx[philo->fork_b], UNLOCK, data,
		data->total_philos);
}

static bool	pick_forks(t_philo *philo, t_data *data)
{
	long	fork_a;
	long	fork_b;
	bool	is_over;

	if (data->total_philos == 1)
		return (handle_single_philo(philo, data));
	fork_a = philo->fork_a;
	fork_b = philo->fork_b;
	if (philo->philo_id % 2)
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
	if (ft_usleep(data->time_to_eat, data))
		exit_error(SLEEP, data, data->total_philos);
	release_forks(philo, data);
	safe_print(PHILO_SLEEP, philo);
	if (ft_usleep(data->time_to_sleep, data))
		exit_error(SLEEP, data, data->total_philos);
	safe_print(PHILO_THINK, philo);
	return (true);
}

void	*dining(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
	philo->data->philos_ready++;
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
		if (usleep(50))
			exit_error(SLEEP, data, data->total_philos);
	}
	while (philo_routine(philo, data))
		if (ft_usleep(1, data))
			exit_error(SLEEP, data, data->total_philos);
	return (NULL);
}
