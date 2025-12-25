/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:24:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:18:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"
# include "printer.h"
# include "safety.h"
# include <stdbool.h>
# include <stdint.h>

/**
 * @fn void exit_error(t_print_code code, t_data *data, long count)
 * @brief Cleans up resources and exits the program with a failure status.
 * @param code  The error code to display.
 * @param data  Pointer to the shared data structure to free.
 * @param count Helper count for destroying a partial list of mutexes.
 */
void	exit_error(t_print_code code, t_data *data, long count);

/**
 * @fn void destroy_mutexes(t_data *data, long count)
 * @brief Destroys all initialized mutexes in the simulation.
 * @param data  Pointer to the shared data structure.
 * @param count The number of forks/philosophers to clean up.
 */
void	destroy_mutexes(t_data *data, long count);

/**
 * @fn long ft_atol(char *str)
 * @brief Converts a string to a long integer.
 * @param str The string to convert.
 * @return The converted long value, or -1 if invalid or overflow occurs.
 */
long	ft_atol(char *str);

/**
 * @fn int64_t ft_gettimeofday_ms(void)
 * @brief Gets the current time of day in milliseconds.
 * @return The current timestamp in ms, or -1 on system call failure.
 */
int64_t	ft_gettimeofday_ms(void);

/**
 * @fn int ft_msleep(long msec, t_data *data)
 * @brief A precise sleep function that checks for simulation end.
 * @details Loops small sleep intervals to remain responsive to death events.
 * @param msec Time to sleep in milliseconds.
 * @param data Pointer to the shared data (to check the `is_over` flag).
 * @return 0 on success.
 */
int		ft_msleep(long msec, t_data *data);

#endif
