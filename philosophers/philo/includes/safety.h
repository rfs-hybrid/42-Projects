/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:10:31 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/18 00:11:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFETY_H
# define SAFETY_H

# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>

typedef enum e_thread_op
{
	CREATE,
	JOIN,
	DETACH,
	INVALID_TH_OP
}	t_th_op;

typedef enum e_mutex_op
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	INVALID_MTX_OP
}	t_mtx_op;

void	*safe_malloc(size_t size);
bool	safe_thread(pthread_t *th, void *(*f)(void *), void *data, t_th_op op);
bool	safe_mutex(t_mtx *mutex, t_mtx_op op);

#endif
