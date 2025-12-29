/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:19:01 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:27:23 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_BONUS_H
# define MONITOR_BONUS_H

# include <stdint.h>
# include <stdlib.h>

/**
 * @fn void *monitor_philo_status(void *arg)
 * @brief Thread routine running inside each philosopher's process.
 * @details Continuously checks if the philosopher has starved. If death is
 * detected, it posts the global `stop` semaphore to signal the parent process.
 * @param arg Void pointer to the `t_philo` structure.
 * @return NULL (Standard pthread return).
 */
void	*monitor_philo_status(void *arg);

/**
 * @fn void *monitor_philo_meals(void *arg)
 * @brief Detached thread routine running in the parent process.
 * @details Waits for `full` semaphore signals equal to the number of philos.
 * If all philos eat enough, it posts the `stop` semaphore to end the simulation.
 * @param arg Void pointer to the `t_data` structure.
 * @return NULL (Standard pthread return).
 */
void	*monitor_philo_meals(void *arg);

#endif
