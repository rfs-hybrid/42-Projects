/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/17 23:41:03 by maaugust         ###   ########.fr       */
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
	size_t		id;
	size_t		meals_eaten;
	size_t		time_last_meal;
	size_t		start_time;
	bool		is_full;
	bool		is_dead;
	t_mtx		*left_fork;
	t_mtx		*right_fork;
	pthread_t	th;
}	t_philo;

typedef struct s_data
{
	size_t	total_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	total_meals;
	bool	is_over;
	t_mtx	*forks;
	t_philo	*philos;
}	t_data;

#endif
