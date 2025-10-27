/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:32 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/27 18:03:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	*monitor(void *arg)
{
	return (NULL);
}

static void	routine(t_philo *philo)
{
	
}

static void	*dining(void *arg)
{
	return (NULL);
}

void	philo_sim(t_data *data)
{
	long	i;

	i = -1;
	if (!safe_thread(&data->monitor, &monitor, data->philos, CREATE))
		exit_error(TH_CREATE, data, data->total_philos);
	while (++i < data->total_philos)
	{
		if (!safe_thread(&data->philos[i].thread, &dining,
				&data->philos[i], CREATE))
			exit_error(TH_CREATE, data, data->total_philos);
	}
	if (!safe_thread(&data->monitor, NULL, NULL, JOIN))
		exit_error(TH_JOIN, data, data->total_philos);
	i = -1;
	while (++i < data->total_philos)
	{
		if (!safe_thread(&data->philos[i].thread, NULL, NULL, DETACH))
			exit_error(TH_DETACH, data, data->total_philos);
	}
}
