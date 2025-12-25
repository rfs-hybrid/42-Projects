/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:16:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFETY_H
# define SAFETY_H

# include "philo.h"
# include "printer.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

/** @brief Operations for safe_thread wrapper. */
typedef enum e_thread_op
{
	CREATE,
	JOIN,
	DETACH,
	INVALID_TH_OP
}	t_th_op;

/** @brief Operations for safe_mutex wrapper. */
typedef enum e_mutex_op
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	INVALID_MTX_OP
}	t_mtx_op;

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
 * @fn void safe_mutex(t_mtx *mutex, t_mtx_op op, t_data *data, long count)
 * @brief Safe wrapper for mutex functions with error handling.
 * @details Exits the program immediately if a mutex operation fails.
 * @param mutex Pointer to the mutex to operate on.
 * @param op    The operation to perform (INIT, LOCK, UNLOCK, DESTROY).
 * @param data  Pointer to the shared data (used for cleanup on error).
 * @param count Helper count for partial cleanup (used during initialization).
 */
void	safe_mutex(t_mtx *mutex, t_mtx_op op, t_data *data, long count);

/**
 * @fn void *safe_malloc(size_t size)
 * @brief Safe wrapper for memory allocation.
 * @param size The number of bytes to allocate.
 * @return Pointer to the allocated memory, or NULL if allocation failed.
 */
void	*safe_malloc(size_t size);

/**
 * @fn void safe_print(t_print_code code, t_philo *philo)
 * @brief Thread-safe wrapper for printing simulation messages.
 * @details Prevents printing if the simulation has already ended.
 * @param code  The message code representing the event.
 * @param philo Pointer to the philosopher involved (or NULL for generic errors).
 */
void	safe_print(t_print_code code, t_philo *philo);

#endif
