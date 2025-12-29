/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:24:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:29:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <semaphore.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "printer_bonus.h"

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void exit_error(t_print_code code, t_data *data)
 * @brief Cleans up resources and exits the program with a failure status.
 * @details Unlinks/Closes semaphores, frees memory, and calls
 * exit(EXIT_FAILURE). Includes guards against infinite recursion during error
 * handling.
 * @param code  The error code to display.
 * @param data  Pointer to the shared data structure to free.
 */
void	exit_error(t_print_code code, t_data *data);

/**
 * @fn void destroy_semaphores(t_data *data)
 * @brief Closes and unlinks all named semaphores used in the simulation.
 * @details Crucial for cleanup; unlinking ensures semaphores are removed from
 * the system kernel, allowing a clean restart.
 * @param data  Pointer to the shared data structure.
 */
void	destroy_semaphores(t_data *data);

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
 * @fn int ft_msleep(long msec)
 * @brief A precise sleep function.
 * @details Loops small sleep intervals to ensure the duration is met accurately.
 * In the bonus, process interruption is handled via signals (SIGKILL), so manual
 * flag checks inside the sleep loop are not required.
 * @param msec Time to sleep in milliseconds.
 * @return 0 on success.
 */
int		ft_msleep(long msec);

#endif
