/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:19:01 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 15:54:09 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_BONUS_H
# define MONITOR_BONUS_H

# include <stddef.h>
# include <stdint.h>

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void *monitor_philo_status(void *arg)
 * @brief Thread routine running inside each philosopher's process.
 * @details Continuously checks if the philosopher has starved. If death is
 * detected, it exits the process with `EXIT_FAILURE`. This exit triggers
 * the parent's `waitpid` to stop the simulation.
 * @param arg Void pointer to the `t_philo` structure.
 * @return NULL (Standard pthread return).
 */
void	*monitor_philo_status(void *arg);

/**
 * @fn void monitor_philo_meals(t_data *data)
 * @brief Routine for the standalone meal monitor process.
 * @details Waits for `full` semaphore signals equal to the number of philos.
 * If all philos eat enough, it exits with `EXIT_SUCCESS`. This exit triggers
 * the parent's `waitpid` to stop the simulation.
 * @param data Pointer to the `t_data` structure.
 */
void	monitor_philo_meals(t_data *data);

#endif
