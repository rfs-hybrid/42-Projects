/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/27 15:20:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_error(t_print_code code, t_data *data, long count)
{
	if (code != MTX_DESTROY)
	{
		print_message(code, NULL);
		if (data->philos && data->forks)
			(void)destroy_mutexes(data, count);
	}
	free(data->philos);
	free(data->forks);
	exit(EXIT_FAILURE);
}

bool	destroy_mutexes(t_data *data, long count)
{
	long	i;

	if (!safe_mutex(&data->writing, DESTROY))
	{
		print_message(MTX_DESTROY, NULL);
		return (false);
	}
	i = -1;
	while (++i < count)
	{
		if (!safe_mutex(&data->forks[i], DESTROY)
			|| !safe_mutex(&data->philos[i].meal_mtx, DESTROY))
		{
			print_message(MTX_DESTROY, NULL);
			return (false);
		}
	}
	return (true);
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
	while (true)
	{
		now = ft_gettimeofday_us();
		if (now == -1)
			return (usleep(usec));
		if (now - start >= (int64_t)usec)
			break ;
		if ((int64_t)usec - (now - start) > 1000LL)
			if (usleep(((int64_t)usec - (now - start)) / 2))
				return (-1);
		else
		{
			now = ft_gettimeofday_us();
			while (now != -1 && now - start < (int64_t)usec)
				now = ft_gettimeofday_us();
			break ;
		}
	}
	return (0);
}
