/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:04:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 15:53:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_BONUS_H
# define SIMULATION_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void simulation(t_data *data)
 * @brief Main simulation control loop.
 * @details Manages the lifecycle of the simulation: creating philosopher
 * processes, creating the meal monitor process, blocking on `waitpid` for any
 * process termination (death, full, or interrupt), and cleaning up all child
 * processes (killing and reaping) to prevent leaks and zombies.
 * @param data Pointer to the shared data structure.
 */
void	simulation(t_data *data);

#endif
