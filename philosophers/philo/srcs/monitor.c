/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:18:03 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/04 17:18:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "philo.h"
#include "printer.h"
#include "safety.h"
#include "utils.h"

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
		if (usleep(50))
			exit_error(SLEEP, data, data->total_philos);
	}
}

static void	initialize_timer(t_data *data)
{
	long	i;

	safe_mutex(&data->ready_mtx, LOCK, data, data->total_philos);
	data->start_time = ft_gettimeofday_ms();
	safe_mutex(&data->ready_mtx, UNLOCK, data, data->total_philos);
	i = -1;
	while (++i < data->total_philos)
	{
		safe_mutex(&data->philos[i].meal_mtx, LOCK, data, data->total_philos);
		data->philos[i].last_meal = data->start_time;
		safe_mutex(&data->philos[i].meal_mtx, UNLOCK, data, data->total_philos);
	}
}

static void	check_meals(t_data *data)
{
	long	i;
	long	full;

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

static void	check_philos(t_data *data)
{
	long	i;
	int64_t	now;
	int64_t	last;

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
		if (ft_usleep(1, data))
			exit_error(SLEEP, data, data->total_philos);
	}
	return (NULL);
}
