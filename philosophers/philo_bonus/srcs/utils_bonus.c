/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/04 16:54:44 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "philo_bonus.h"
#include "safety_bonus.h"

/**
 * @fn void exit_error(t_print_code code, t_data *data)
 * @brief Handles fatal errors by printing a message and cleaning up.
 * @details Destroys semaphores, frees memory, and exits.
 * Guards against recursion: if the error is a semaphore destruction error,
 * it skips the destroy step.
 * @param code Error code.
 * @param data Pointer to data structure.
 */
void	exit_error(t_print_code code, t_data *data)
{
	print_message(code, NULL);
	if (data->philos)
	{
		if (code != SEM_CLOSE && code != SEM_UNLINK)
			destroy_semaphores(data);
		free(data->philos);
	}
	exit(EXIT_FAILURE);
}

/**
 * @fn void destroy_semaphores(t_data *data)
 * @brief Closes and unlinks all named semaphores.
 * @details Ensures that the semaphores are removed from the system so they
 * do not persist after the program ends.
 * @param data Pointer to data structure.
 */
void	destroy_semaphores(t_data *data)
{
	long	i;

	if (sem_close(data->stop) != 0 || sem_close(data->print) != 0
		|| sem_close(data->full) != 0 || sem_close(data->waiter) != 0
		|| sem_close(data->forks) != 0)
		exit_error(SEM_CLOSE, data);
	if (data->philos)
	{
		i = -1;
		while (++i < data->total_philos)
			if (data->philos[i].meal != SEM_FAILED
				&& sem_close(data->philos[i].meal) != 0)
				exit_error(SEM_CLOSE, data);
	}
	if (sem_unlink(SEM_STOP) != 0 || sem_unlink(SEM_PRINT) != 0
		|| sem_unlink(SEM_FULL) != 0 || sem_unlink(SEM_WAITER) != 0
		|| sem_unlink(SEM_FORKS) != 0)
		exit_error(SEM_UNLINK, data);
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
 * @fn int ft_msleep(long msec)
 * @brief Precise sleep function.
 * @details Sleeps for the specified duration in milliseconds. Loops with short
 * sleeps for precision. Note: In the bonus, we do not need to check an `is_over`
 * flag here because the parent process uses `SIGKILL` to interrupt sleeps.
 * @param msec Duration to sleep in milliseconds.
 * @return 0 on success.
 */
int	ft_msleep(long msec)
{
	int64_t	start;
	int64_t	now;

	start = ft_gettimeofday_ms();
	if (start == -1)
		return (usleep(msec * 1000));
	now = start;
	while (now - start < (int64_t)msec)
	{
		usleep(100);
		now = ft_gettimeofday_ms();
	}
	return (0);
}
