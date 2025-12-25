/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:14:24 by maaugust         ###   ########.fr       */
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

/** @brief Alias for pthread_mutex_t to save typing. */
typedef pthread_mutex_t	t_mtx;

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @brief Represents a single philosopher.
 * @param philo_id    The philosopher's unique ID (1 to total_philos).
 * @param meals_eaten The number of meals this philosopher has consumed.
 * @param last_meal   Timestamp (in ms) of the start of the last meal.
 * @param fork_a      Index of the first fork to lock (resource hierarchy).
 * @param fork_b      Index of the second fork to lock.
 * @param meal_mtx    Mutex protecting `last_meal` and `meals_eaten`.
 * @param thread      The thread ID associated with this philosopher.
 * @param data        Pointer to the shared simulation data.
 */
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

/**
 * @brief Shared data structure containing simulation rules and resources.
 * @param total_philos  Total number of philosophers and forks.
 * @param time_to_die   Maximum time (in ms) a philosopher can survive without
 * eating.
 * @param time_to_eat   Time (in ms) it takes to eat.
 * @param time_to_sleep Time (in ms) spent sleeping.
 * @param total_meals   Minimum number of meals per philosopher (-1 if infinite).
 * @param philos_ready  Counter for the number of threads ready to start.
 * @param start_time    Timestamp (in ms) when the simulation officially begins.
 * @param is_over       Flag indicating if the simulation should stop (death or
 * full).
 * @param print_mtx     Mutex for ensuring thread-safe printing.
 * @param status_mtx    Mutex for reading/writing the `is_over` flag.
 * @param ready_mtx     Mutex for protecting `philos_ready` and `start_time`.
 * @param forks_mtx     Array of mutexes representing the forks.
 * @param philos        Array of philosopher structures.
 * @param monitor       The thread ID for the monitor.
 */
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
	t_mtx		print_mtx;
	t_mtx		status_mtx;
	t_mtx		ready_mtx;
	t_mtx		*forks_mtx;
	t_philo		*philos;
	pthread_t	monitor;
}	t_data;

#endif
