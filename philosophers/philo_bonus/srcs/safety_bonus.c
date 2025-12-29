/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:18:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safety_bonus.h"
#include "philo_bonus.h"
#include "utils_bonus.h"

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
 * @fn void safe_sem(sem_t *sem, t_sem_op op, t_data *data)
 * @brief Wrapper for semaphore functions with error handling.
 * @details Handles POST and WAIT operations. Exits the program if a semaphore
 * operation fails.
 * @param sem Pointer to the semaphore.
 * @param op Operation type (POST or WAIT).
 * @param data Pointer to data (for cleanup on error).
 */
void	safe_sem(sem_t *sem, t_sem_op op, t_data *data)
{
	int	ret;

	ret = -1;
	if (op == POST)
		ret = sem_post(sem);
	else if (op == WAIT)
		ret = sem_wait(sem);
	else
		exit_error(SEM_INVALID, data);
	if (ret != 0)
	{
		if (op == POST)
			exit_error(SEM_POST, data);
		else if (op == WAIT)
			exit_error(SEM_WAIT, data);
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
 * @brief Thread/Process-safe wrapper for printing simulation events.
 * @details Locks the `print` semaphore to ensure messages don't overlap.
 * Crucial Logic: If the message is `PHILO_DEAD`, the semaphore is NOT
 * unlocked. This creates a "death grip" that prevents any other process from
 * printing subsequent messages, ensuring the death log is the final output.
 * @param code Message code.
 * @param philo Pointer to the philosopher.
 */
void	safe_print(t_print_code code, t_philo *philo)
{
	safe_sem(philo->data->print, WAIT, philo->data);
	print_message(code, philo);
	if (code != PHILO_DEAD)
		safe_sem(philo->data->print, POST, philo->data);
}
