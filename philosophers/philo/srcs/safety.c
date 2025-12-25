/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 15:53:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safety.h"
#include "utils.h"

/**
 * @fn bool safe_thread(pthread_t *th, void *(*f)(void *), void *arg,
 * t_th_op op)
 * @brief Wrapper for pthread functions to handle errors.
 * @details Abstraction for create, join, and detach operations.
 * @param th Pointer to the pthread_t variable.
 * @param f Function pointer for thread routine (create only).
 * @param arg Argument for the thread routine (create only).
 * @param op Operation type (CREATE, JOIN, DETACH).
 * @return true on success, false on failure.
 */
bool	safe_thread(pthread_t *th, void *(*f)(void *), void *arg, t_th_op op)
{
	int	ret;

	ret = -1;
	if (op == CREATE)
		ret = pthread_create(th, NULL, f, arg);
	else if (op == JOIN)
		ret = pthread_join(*th, NULL);
	else if (op == DETACH)
		ret = pthread_detach(*th);
	return (ret == 0);
}

/**
 * @fn void safe_mutex(t_mtx *mutex, t_mtx_op op, t_data *data, long count)
 * @brief Wrapper for mutex functions with error handling.
 * @details Handles INIT, LOCK, UNLOCK, and DESTROY operations. Exits the program
 * if a mutex operation fails.
 * @param mutex Pointer to the mutex.
 * @param op Operation type.
 * @param data Pointer to data (for cleanup on error).
 * @param count Count for cleanup (number of philos initialized so far).
 */
void	safe_mutex(t_mtx *mutex, t_mtx_op op, t_data *data, long count)
{
	int	ret;

	ret = -1;
	if (op == INIT)
		ret = pthread_mutex_init(mutex, NULL);
	else if (op == LOCK)
		ret = pthread_mutex_lock(mutex);
	else if (op == UNLOCK)
		ret = pthread_mutex_unlock(mutex);
	else if (op == DESTROY)
		ret = pthread_mutex_destroy(mutex);
	else
		exit_error(MTX_INVALID, data, count);
	if (ret != 0)
	{
		if (op == INIT)
			exit_error(MTX_INIT, data, count);
		else if (op == LOCK)
			exit_error(MTX_LOCK, data, count);
		else if (op == UNLOCK)
			exit_error(MTX_UNLOCK, data, count);
		else if (op == DESTROY)
			exit_error(MTX_DESTROY, data, count);
	}
}

/**
 * @fn void *safe_malloc(size_t size)
 * @brief Safe memory allocation wrapper.
 * @details Calls malloc and checks for NULL return.
 * @param size Bytes to allocate.
 * @return Pointer to allocated memory, or NULL on failure.
 */
void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

/**
 * @fn void safe_print(t_print_code code, t_philo *philo)
 * @brief Thread-safe wrapper for printing simulation events.
 * @details Locks the `print_mtx` to ensure messages don't overlap.
 * Also checks `is_over` status to prevent printing after death (unless it is
 * the death message).
 * @param code Message code.
 * @param philo Pointer to the philosopher.
 */
void	safe_print(t_print_code code, t_philo *philo)
{
	t_data	*data;
	bool	print_ready;

	data = philo->data;
	print_ready = false;
	safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
	if (!data->is_over)
		print_ready = true;
	if (!data->is_over && code == PHILO_DEAD)
		data->is_over = true;
	safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	if (!print_ready)
		return ;
	safe_mutex(&data->print_mtx, LOCK, data, data->total_philos);
	safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
	if (data->is_over && code != PHILO_DEAD)
	{
		safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
		safe_mutex(&data->print_mtx, UNLOCK, data, data->total_philos);
		return ;
	}
	safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
	print_message(code, philo);
	safe_mutex(&data->print_mtx, UNLOCK, data, data->total_philos);
}
