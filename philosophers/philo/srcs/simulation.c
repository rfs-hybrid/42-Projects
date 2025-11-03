/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/03 22:00:25 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "simulation.h"
#include "utils.h"

static void	pick_forks(t_philo *philo, t_data *data)
{
	long	first;
	long	second;

	first = philo->fork_a;
	second = philo->fork_b;
	if (data->total_philos == 1)
	{
		safe_mutex(&data->forks_mtx[first], LOCK, data, data->total_philos);
		safe_print(PHILO_FORK, philo);
		return ;
	}
	if (philo->fork_a > philo->fork_b)
	{
		first = philo->fork_b;
		second = philo->fork_a;
	}
	if (philo->philo_id % 2 && usleep(50))
		exit_error(SLEEP, data, data->total_philos);
	safe_mutex(&data->forks_mtx[first], LOCK, data, data->total_philos);
	safe_print(PHILO_FORK, philo);
	safe_mutex(&data->forks_mtx[second], LOCK, data, data->total_philos);
	safe_print(PHILO_FORK, philo);
}

static void	finish_meal(t_philo *philo, t_data *data)
{
	if (philo->philo_id % 2)
	{
		safe_mutex(&data->forks_mtx[philo->fork_b], UNLOCK, data,
			data->total_philos);
		safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
			data->total_philos);
	}
	else
	{
		safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
			data->total_philos);
		safe_mutex(&data->forks_mtx[philo->fork_b], UNLOCK, data,
			data->total_philos);
	}
	safe_print(PHILO_SLEEP, philo);
	if (ft_usleep(data->time_to_sleep, data))
		exit_error(SLEEP, data, data->total_philos);
	safe_print(PHILO_THINK, philo);
}

static bool	philo_routine(t_philo *philo, t_data *data)
{
	safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
	if (data->is_over)
	{
		safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
		return (false);
	}
	safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	pick_forks(philo, data);
	if (data->total_philos == 1)
	{
		if (ft_usleep(data->time_to_die, data))
			exit_error(SLEEP, data, data->total_philos);
		safe_mutex(&data->forks_mtx[philo->fork_a], UNLOCK, data,
			data->total_philos);
		return (false);
	}
	safe_mutex(&philo->meal_mtx, LOCK, data, data->total_philos);
	philo->last_meal = ft_gettimeofday_ms();
	philo->meals_eaten += 1;
	safe_print(PHILO_EAT, philo);
	safe_mutex(&philo->meal_mtx, UNLOCK, data, data->total_philos);
	if (ft_usleep(data->time_to_eat, data))
		exit_error(SLEEP, data, data->total_philos);
	finish_meal(philo, data);
	return (true);
}

static void	*dining(void *arg)
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
		;
	return (NULL);
}

void	philo_sim(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->total_philos)
	{
		if (!safe_thread(&data->philos[i].thread, &dining,
				&data->philos[i], CREATE))
			exit_error(TH_CREATE, data, data->total_philos);
	}
	if (!safe_thread(&data->monitor, &monitor, data, CREATE))
		exit_error(TH_CREATE, data, data->total_philos);
	if (!safe_thread(&data->monitor, NULL, NULL, JOIN))
		exit_error(TH_JOIN, data, data->total_philos);
	i = -1;
	while (++i < data->total_philos)
		if (!safe_thread(&data->philos[i].thread, NULL, NULL, JOIN))
			exit_error(TH_JOIN, data, data->total_philos);
}
