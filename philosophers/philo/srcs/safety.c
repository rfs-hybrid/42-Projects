/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/04 19:23:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safety.h"
#include "utils.h"

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

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

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
