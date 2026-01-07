/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:07:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 15:55:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// Semaphore Names
# define SEM_PRINT	"/philo_print"
# define SEM_MEAL	"/philo_meal_"
# define SEM_FULL	"/philo_full"
# define SEM_WAITER	"/philo_waiter"
# define SEM_FORKS	"/philo_forks"

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @brief Represents a single philosopher process.
 * @param philo_id    The philosopher's unique ID (1 to total_philos).
 * @param meals_eaten The number of meals this philosopher has consumed.
 * @param last_meal   Timestamp (in ms) of the start of the last meal.
 * @param pid         The Process ID of the philosopher (child process).
 * @param meal        Named semaphore unique to this philosopher (protects data).
 * @param monitor     The Thread ID of the internal death monitor thread.
 * @param data        Pointer to the shared simulation data.
 */
typedef struct s_philo
{
	long		philo_id;
	long		meals_eaten;
	int64_t		last_meal;
	pid_t		pid;
	sem_t		*meal;
	pthread_t	monitor;
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
 * @param start_time    Timestamp (in ms) when the simulation officially begins.
 * @param print         Semaphore used to serialize output operations.
 * @param full          Semaphore used to count how many philosophers are full.
 * @param waiter        Semaphore used to limit concurrent diners (deadlock
 * prevent).
 * @param forks         Semaphore representing the pool of available forks.
 * @param philos        Array of philosopher structures.
 */
typedef struct s_data
{
	long		total_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		total_meals;
	int64_t		start_time;
	sem_t		*print;
	sem_t		*full;
	sem_t		*waiter;
	sem_t		*forks;
	t_philo		*philos;
}	t_data;

#endif
