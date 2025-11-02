/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/02 16:16:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

typedef struct s_philo
{
	long		philo_id;
	long		meals_eaten;
	int64_t		last_meal;
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
	long		philos_ready;
	int64_t		start_time;
	bool		is_over;
	t_mtx		write_mtx;
	t_mtx		status_mtx;
	t_mtx		ready_mtx;
	t_mtx		*forks_mtx;
	t_philo		*philos;
	pthread_t	monitor;
}	t_data;

#endif
