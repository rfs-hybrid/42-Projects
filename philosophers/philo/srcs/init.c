/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:20 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/18 00:14:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"

bool	philo_init(t_data *data, char **argv)
{
	// int	i;

	data->total_philos = ft_atoul(*argv++);
	data->time_to_die = ft_atoul(*argv++);
	data->time_to_eat = ft_atoul(*argv++);
	data->time_to_sleep = ft_atoul(*argv++);
	data->total_meals = 0;
	if (*argv)
		data->total_meals = ft_atoul(*argv);
	// i = -1;
	data->philos = (t_philo *) malloc(sizeof(t_philo) * data->total_philos);
	data->forks = (t_mtx *) malloc(sizeof(t_mtx) * data->total_philos);
	return (true);
}
