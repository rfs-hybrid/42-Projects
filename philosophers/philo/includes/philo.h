/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/18 18:34:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	long		philo_id;
	long		meals_eaten;
	long		last_meal;
	long		fork_a;
	long		fork_b;
	t_mtx		meal_mtx;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	long		total_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		total_meals;
	long		philos_done;
	long		start_time;
	bool		is_over;
	t_mtx		writing;
	t_mtx		*forks;
	t_philo		*philos;
	pthread_t	monitor;
}	t_data;

#endif
