/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/24 15:22:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "safety.h"

bool	safe_thread(pthread_t *th, void *(*f)(void *), void *data, t_th_op op)
{
	int	ret;

	ret = -1;
	if (op == CREATE)
		ret = pthread_create(th, NULL, f, data);
	else if (op == JOIN)
		ret = pthread_join(*th, NULL);
	else if (op == DETACH)
		ret = pthread_detach(*th);
	return (ret == 0);
}

bool	safe_mutex(t_mtx *mutex, t_mtx_op op)
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
	return (ret == 0);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
