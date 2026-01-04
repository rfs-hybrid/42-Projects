/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/04 16:56:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"
#include "safety.h"

/**
 * @fn void exit_error(t_print_code code, t_data *data, long count)
 * @brief Handles fatal errors by printing a message and cleaning up.
 * @details Destroys mutexes, frees memory, and exits the program with failure
 * status.
 * @param code Error code.
 * @param data Pointer to data structure.
 * @param count Number of initialized items (for partial cleanup).
 */
void	exit_error(t_print_code code, t_data *data, long count)
{
	print_message(code, NULL);
	if (data->philos && data->forks_mtx && code != MTX_DESTROY)
		destroy_mutexes(data, count);
	free(data->philos);
	free(data->forks_mtx);
	exit(EXIT_FAILURE);
}

/**
 * @fn void destroy_mutexes(t_data *data, long count)
 * @brief Destroys all initialized mutexes.
 * @param data Pointer to data structure.
 * @param count Number of fork/meal mutexes to destroy.
 */
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

/**
 * @fn long ft_atol(char *str)
 * @brief Converts a string to a long integer.
 * @details Robust conversion that handles spacing, signs and letters.
 * @param str The string to convert.
 * @return The converted value, or -1 if invalid/overflow.
 */
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
		res = res * 10 + (*str++ - '0');
		if (res < prev)
			return (-1);
	}
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str)
		return (-1);
	return (res);
}

/**
 * @fn int64_t ft_gettimeofday_ms(void)
 * @brief Gets the current time of day in milliseconds.
 * @return Current timestamp in ms, or -1 on error.
 */
int64_t	ft_gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((int64_t)tv.tv_sec * 1000LL + (int64_t)tv.tv_usec / 1000LL);
}

/**
 * @fn int ft_msleep(long msec, t_data *data)
 * @brief Precise sleep function.
 * @details Sleeps for the specified duration in milliseconds. Instead of a
 * single long `usleep`, it loops with short sleeps to periodically check if
 * the simulation has ended, ensuring responsive exit on death.
 * @param msec Duration to sleep in milliseconds.
 * @param data Pointer to data (to check `is_over` status).
 * @return 0 on success.
 */
int	ft_msleep(long msec, t_data *data)
{
	int64_t	start;
	int64_t	now;

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
		usleep(100);
		now = ft_gettimeofday_ms();
	}
	return (0);
}
