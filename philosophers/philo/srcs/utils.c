/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/02 16:16:38 by maaugust         ###   ########.fr       */
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

	safe_mutex(&data->write_mtx, DESTROY, data, count);
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

int64_t	ft_gettimeofday_us(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((int64_t) tv.tv_sec * 1000000LL + (int64_t) tv.tv_usec);
}

int	ft_usleep(long usec)
{
	int64_t	start;
	int64_t	now;

	start = ft_gettimeofday_us();
	if (start == -1)
		return (usleep(usec));
	now = ft_gettimeofday_us();
	if (now == -1)
		return (usleep(usec));
	while (now - start < usec)
	{
		now = ft_gettimeofday_us();
		if (now == - 1)
			return (usleep(usec));
		if (usec - (now - start) > 1000 && usleep(500))
			return (-1);
		else if (usleep(100))
			return (-1);
	}
	return (0);
}
