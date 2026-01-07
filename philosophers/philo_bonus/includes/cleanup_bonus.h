/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:10:05 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 17:51:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_BONUS_H
# define CLEANUP_BONUS_H

# include <semaphore.h>
# include <stdbool.h>
# include <stdlib.h>

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void close_semaphores(t_data *data)
 * @brief Closes open semaphore descriptors in the current process.
 * @details Safe for both parent and child processes to use.
 * @param data Pointer to the shared data structure.
 */
void	close_semaphores(t_data *data);

/**
 * @fn void cleanup(t_data *data)
 * @brief Orchestrates the full cleanup sequence (unlink, close, free).
 * @param data Pointer to the shared data structure.
 */
void	cleanup(t_data *data);

#endif
