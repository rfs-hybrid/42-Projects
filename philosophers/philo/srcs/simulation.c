/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/29 04:16:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "simulation.h"
#include "utils.h"

static void	philo_routine(t_philo *philo)
{
	
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
		if (!safe_thread(&data->philos[i].thread, NULL, NULL, DETACH))
			exit_error(TH_DETACH, data, data->total_philos);
	}
	if (!safe_thread(&data->monitor, &monitor, data, CREATE))
		exit_error(TH_CREATE, data, data->total_philos);
	if (!safe_thread(&data->monitor, NULL, NULL, JOIN))
		exit_error(TH_JOIN, data, data->total_philos);
}
