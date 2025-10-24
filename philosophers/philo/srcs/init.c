/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:20 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/24 16:35:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"
#include "printer.h"
#include "safety.h"

static void	mutexes_init(t_data *data)
{
	long	i;

	if (!(safe_mutex(&data->writing, INIT)))
		exit_error(MTX_INIT, data, 0);
	i = -1;
	while (++i < data->total_philos)
		if (!safe_mutex(&data->forks[i], INIT)
			|| !safe_mutex(&data->philos[i].meal_mtx, INIT))
			exit_error(MTX_INIT, data, i);
}

static void	philo_data(t_data *data, t_philo *philo, long index, long total)
{
	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = index + 1;
	philo->meals_eaten = 0;
	philo->fork_a = index;
	philo->fork_b = (index + 1) % total;
	philo->data = data;
}

void	philo_init(t_data *data, char **argv)
{
	long	i;

	data->total_philos = ft_atol(*argv++);
	data->time_to_die = ft_atol(*argv++);
	data->time_to_eat = ft_atol(*argv++);
	data->time_to_sleep = ft_atol(*argv++);
	data->total_meals = -1;
	if (*argv)
		data->total_meals = ft_atol(*argv);
	data->philos = safe_malloc(sizeof(t_philo) * data->total_philos);
	data->forks = safe_malloc(sizeof(t_mtx) * data->total_philos);
	if (!data->philos || !data->forks)
		exit_error(MALLOC, data, 0);
	i = -1;
	while (++i < data->total_philos)
		philo_data(data, &data->philos[i], i, data->total_philos);
	mutexes_init(data);
}
