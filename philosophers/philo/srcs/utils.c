/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/03 22:25:14 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_error(t_print_code code, t_data *data, long count)
{
	print_message(code, NULL);
	if (data->philos && data->forks_mtx && code != MTX_DESTROY)
		destroy_mutexes(data, count);
	free(data->philos);
	free(data->forks_mtx);
	exit(EXIT_FAILURE);
}

void	destroy_mutexes(t_data *data, long count)
{
	long	i;

	safe_mutex(&data->print_mtx, DESTROY, data, count);
	safe_mutex(&data->status_mtx, DESTROY, data, count);
	safe_mutex(&data->ready_mtx, DESTROY, data, count);
	i = -1;
	while (++i < count)
	{
		safe_mutex(&data->forks_mtx[i], DESTROY, data, count);
		safe_mutex(&data->philos[i].meal_mtx, DESTROY, data, count);
	}
}

long	ft_atol(char *str)
{
	long	res;
	long	prev;

	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = res;
		res = res * 10 + *str++ - '0';
		if (res < prev)
			return (-1);
	}
	return (res);
}

int64_t	ft_gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((int64_t)tv.tv_sec * 1000LL + (int64_t)tv.tv_usec / 1000LL);
}

int	ft_usleep(long msec, t_data *data)
{
	int64_t	start;
	int64_t	now;
	int64_t	remaining;

	start = ft_gettimeofday_ms();
	if (start == -1)
		return (usleep(msec * 1000));
	now = start;
	while (now - start < (int64_t)msec)
	{
		safe_mutex(&data->status_mtx, LOCK, data, data->total_philos);
		if (data->is_over)
		{
			safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
			return (0);
		}
		safe_mutex(&data->status_mtx, UNLOCK, data, data->total_philos);
		remaining = msec - (now - start);
		if (remaining > 10)
			usleep(5000);
		else if (remaining > 0)
			usleep(remaining * 500);
		now = ft_gettimeofday_ms();
	}
	return (0);
}
