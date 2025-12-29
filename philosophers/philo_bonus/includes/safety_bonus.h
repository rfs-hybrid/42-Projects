/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:26:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFETY_BONUS_H
# define SAFETY_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stdlib.h>
# include "printer_bonus.h"

/** @brief Forward declaration of philosopher structure. */
typedef struct s_philo	t_philo;

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/** @brief Operations for safe_thread wrapper. */
typedef enum e_thread_op
{
	CREATE,
	JOIN,
	DETACH,
	INVALID_TH_OP
}	t_th_op;

/** @brief Operations for safe_sem wrapper. */
typedef enum e_sem_op
{
	POST,
	WAIT,
	INVALID_SEM_OP
}	t_sem_op;

/**
 * @fn bool safe_thread(pthread_t *th, void *(*f)(void *), void *arg,
 * t_th_op op)
 * @brief Safe wrapper for pthread functions with error checking.
 * @param th   Pointer to the thread ID variable.
 * @param f    Function pointer for the thread routine (used for CREATE).
 * @param data Argument for the thread routine (used for CREATE).
 * @param op   The operation to perform (CREATE, JOIN, or DETACH).
 * @return true if the operation succeeded, false otherwise.
 */
bool	safe_thread(pthread_t *th, void *(*f)(void *), void *data, t_th_op op);

/**
 * @fn void safe_sem(sem_t *sem, t_sem_op op, t_data *data)
 * @brief Safe wrapper for semaphore functions with error handling.
 * @details Exits the program immediately if a semaphore operation fails.
 * @param sem  Pointer to the semaphore to operate on.
 * @param op   The operation to perform (POST, WAIT).
 * @param data Pointer to the shared data (used for cleanup on error).
 */
void	safe_sem(sem_t *sem, t_sem_op op, t_data *data);

/**
 * @fn void *safe_malloc(size_t size)
 * @brief Safe wrapper for memory allocation.
 * @param size The number of bytes to allocate.
 * @return Pointer to the allocated memory, or NULL if allocation failed.
 */
void	*safe_malloc(size_t size);

/**
 * @fn void safe_print(t_print_code code, t_philo *philo)
 * @brief Process-safe wrapper for printing simulation messages.
 * @details locks the `print` semaphore to ensure messages are serialized.
 * Special Logic: If `code` is PHILO_DEAD, the semaphore is NOT unlocked,
 * permanently blocking output from other processes to strictly satisfy the
 * "no logs after death" requirement.
 * @param code  The message code representing the event.
 * @param philo Pointer to the philosopher involved (or NULL for generic errors).
 */
void	safe_print(t_print_code code, t_philo *philo);

#endif
