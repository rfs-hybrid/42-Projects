/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/18 00:19:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "safety.h"
#include "printer.h"

static bool	check_error(int ret, t_print_code code)
{
	if (ret)
	{
		print_message(code, NULL);
		return (false);
	}
	return (true);
}

static t_print_code	conv_to_print_code(int op, bool is_thread)
{
	if (is_thread)
	{
		if (op == CREATE)
			return (TH_CREATE);
		else if (op == JOIN)
			return (TH_JOIN);
		else if (op == DETACH)
			return (TH_DETACH);
		return (TH_INVALID);
	}
	if (op == INIT)
		return (MTX_INIT);
	else if (op == LOCK)
		return (MTX_LOCK);
	else if (op == UNLOCK)
		return (MTX_UNLOCK);
	else if (op == DESTROY)
		return (MTX_DESTROY);
	return (MTX_INVALID);
}

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
	else
		op = INVALID_TH_OP;
	return (check_error(ret, conv_to_print_code((int)op, true)));
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
	else
		op = INVALID_MTX_OP;
	return (check_error(ret, conv_to_print_code((int)op, false)));
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_message(MALLOC, NULL);
	return (ptr);
}
